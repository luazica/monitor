package main

import(
  "fmt"
	"net/http"
  "encoding/json"
)

type SensorData struct {
  Humidity int `json:"humidity"`
  Triggered bool `json:"triggered"`
}

var currentData SensorData
func SensorHandler(w http.ResponseWriter, r *http.Request) {
  w.Header().Set("Access-Control-Allow-Origin", "*")//C.O.R.S.
  var data SensorData

  switch r.Method {
    case http.MethodPost:
      err := json.NewDecoder(r.Body).Decode(&data)
        if err != nil {
          fmt.Println("json invalido")
          http.Error(w, "invalid JSON", http.StatusBadRequest)
          return
        }
        currentData = data

        fmt.Println("umidade:", data.Humidity)
        fmt.Println("critico:", data.Triggered)
        w.Write([]byte("dados recebidos\n"))

    case http.MethodGet:
      w.Header().Set("Content-Type", "application/json")
      json.NewEncoder(w).Encode(currentData)

    default:
      fmt.Println("metodo invalido")
      http.Error(w, "invalid method", http.StatusMethodNotAllowed)
    }
}
