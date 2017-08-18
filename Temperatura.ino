#include <DHT.h>
#include <Adafruit_Sensor.h>
#define DHTTYPE DHT11 //Establesca el modelo a utilizar

const int DHTpin=5;

DHT dht(DHTpin,DHTTYPE);


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Test");
  dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
float h=dht.readHumidity();
float t=dht.readTemperature();
delay(2000);

if(isnan(h) | isnan(t)){
Serial.println("Fallo la lectura del sensor");
return;
}
Serial.print("Humedad:");
Serial.print("h");
Serial.print("Temperatura:");
Serial.print("t");
Serial.print("\n");



}
