const int ledpin=13;//
const int ldrpin=A0;


void setup() {
Serial.begin(9600);
pinMode(ledpin, OUTPUT);
pinMode(ldrpin, INPUT);

}

void loop() {

int ldrStatus=analogRead(ldrpin);
Serial.print(ldrStatus);
Serial.print("\n");
if(ldrStatus>100)
  digitalWrite(ledpin,HIGH);
  else
  digitalWrite(ledpin,LOW);
delay(100);
}
