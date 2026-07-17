package main

import (
	"encoding/json"
	"fmt"
	"net/http"
)

type SensorData struct {
	Humidity  int  `json:"humidity"`
	Triggered bool `json:"triggered"`
}

var currentData SensorData

func SensorHandler(w http.ResponseWriter, r *http.Request) {
	w.Header().Set("Access-Control-Allow-Origin", "*") //C.O.R.S.
	w.Header().Set("Access-Control-Allow-Methods", "GET, POST, OPTIONS")
	w.Header().Set("Access-Control-Allow-Headers", "Content-Type")

	var data SensorData

	switch r.Method {
	case http.MethodPost:
		err := json.NewDecoder(r.Body).Decode(&data)
		if err != nil {
			fmt.Println("invalid JSON")
			http.Error(w, "invalid JSON", http.StatusBadRequest)
			return
		}
		currentData = data

		fmt.Println("humidity:", data.Humidity)
		fmt.Println("triggered:", data.Triggered)
		w.Write([]byte("data received\n"))

	case http.MethodGet:
		w.Header().Set("Content-Type", "application/json")
		json.NewEncoder(w).Encode(currentData)

	case http.MethodOptions:
		w.WriteHeader(http.StatusNoContent) // ou http.StatusOK
		return

	default:
		fmt.Println("invalid method")
		http.Error(w, "invalid method", http.StatusMethodNotAllowed)
	}
}
