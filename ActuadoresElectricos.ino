const int pinSensor=3;
const int pinTransitor=4;
int estado;
void setup() {
  // put your setup code here, to run once:


pinMode(pinSensor,INPUT);
pinMode(pinTransitor,OUTPUT);
digitalWrite(pinTransitor,LOW);
}
void loop() {
  // put your main code here, to run repeatedly:
estado=digitalRead (pinSensor);
if(estado ==HIGH){
  digitalWrite(pinTransitor, HIGH);
}
else{
  digitalWrite(pinTransitor,LOW);
}
}
