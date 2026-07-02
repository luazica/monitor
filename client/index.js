let triggered = false;
let humidity
let sensor_online;
let api_online;

async function checkAPI() {
  try {
    const response = await fetch("/api/sensor");
    const api_online = response.ok;

    document.getElementById("api_online").innerText = api_online;
  } catch (err) {
    console.log("error:", err);
  }
}
checkAPI();

//function checkSensor(){
//
//}

async function getData() {
  try {
    const response = await fetch("/api/sensor");
    const responseData = await response.json();

    document.getElementById("humidity").innerText = responseData.humidity;
    document.getElementById("status").innerText = responseData.triggered;
  } catch (err) {
    console.log("error:", err);
  }
}

const button = document.getElementById('button');
button.addEventListener('click', async function () {
  if (!triggered) {
    triggered = true;
  } else {
    triggered = false;
  }

  const response = await fetch("/api/sensor");
  const responseData = await response.json();

  const data = {
    humidity: responseData.humidity,
    triggered: (triggered) ? true : false
  };

  const sendData = {
    method: 'POST',
    headers: {
      'Content-Type': 'application/json'
    },
    body: JSON.stringify(data)
  };

  await fetch("/api/sensor", sendData)
    .then(res => res.json())
    .then(sended => {
      console.log("sucess: ", sended)
    })
});
setInterval(getData, 1000);
