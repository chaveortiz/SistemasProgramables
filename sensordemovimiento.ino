const int sensorpin=A5;//
const int ledpin=13;


void setup() {
Serial.begin(9600);
pinMode(sensorpin, OUTPUT);
pinMode(ledpin, OUTPUT);

}
 
void loop() {

int SensorStatus=analogRead(sensorpin);
Serial.print(SensorStatus);
Serial.print("\n");
  digitalWrite(ledpin,SensorStatus);
 
delay(100);
}
