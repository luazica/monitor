#!/bin/bash

cd ~/Mesa/humidity_monitor/api
go run . &

API_PID=$!

cd ~/Mesa/humidity_monitor/api
source .venv/bin/activate
python gateway.py &

PY_PID=$!

echo ""
echo "all services started"
echo "API PID: $API_PID"
echo "Python PID: $PY_PID"
echo "Frontend PID: $FRONT_PID"

wait