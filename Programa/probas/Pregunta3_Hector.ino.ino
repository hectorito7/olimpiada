#include <ESP32Servo.h>
#include "ABlocks_DHT.h"

double Temperatura;
double Humedad;
Servo servo_18;
DHT dht23(23,DHT11);

void setup()
{
  	servo_18.attach(18);
	pinMode(23, INPUT);

	Serial.begin(115200);
	Serial.flush();
	while(Serial.available()>0)Serial.read();

	dht23.begin();

	servo_18.write(3);

}


void loop()
{
	yield();

  	Temperatura = dht23.readTemperature();
  	Serial.println(String("Temperatura: ")+String(Temperatura));
  	Humedad = dht23.readHumidity();
  	Serial.println(String("Humedad: ")+String(Humedad));
  	if (((Humedad > 50) || (Temperatura < 50))) {
  		servo_18.write(90);
  	}
  	else {
  		servo_18.write(3);
  	}

  	delay(3000);

}