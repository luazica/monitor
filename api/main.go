package main

import (
	"fmt"
	"net/http"
)

func main() {
	http.HandleFunc("/api/sensor", SensorHandler)
	http.Handle("/", http.FileServer(http.Dir("../client")))

	fmt.Println("server running in 8080...")
	err := http.ListenAndServe(":8080", nil)

	if err != nil {
		fmt.Println("erro: ", err)
	}
}
