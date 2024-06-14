from flask import Flask, request

app = Flask(__name__)
Data =[]

@app.route('/data', methods=['POST'])
def receive_data():
    Temperature = request.args.get("temperature")
    Humidity = request.args.get("humidity")
    data = [Temeperature, Humidity]

    data.append[data]
    # Process the sensor data here
    print(f"Received sensor value: {data}")
    return data({"message": "Data received successfully", "sensorValue": data}), 200

if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000)
