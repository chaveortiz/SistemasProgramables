const int EchoPin = 5;
const int TriggerPin = 6;
const int LedPin = 2;
const int LedPinG = 7;
 
void setup() {
   Serial.begin(9600);
   pinMode(LedPin, OUTPUT);
   pinMode(LedPinG, OUTPUT);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
}
 
void loop() {
   int cm = ping(TriggerPin, EchoPin);
   Serial.println(String(cm) + " cm.");

   int Limite = 20 ;

   if (cm < Limite)
   digitalWrite(LedPin, HIGH);
   else
   digitalWrite(LedPin, LOW);

   delay(1000);
}
 
int ping(int TriggerPin, int EchoPin) {
   long duracion, distanciaCm;

   digitalWrite(TriggerPin, LOW);
   digitalWrite(LedPinG, LOW);
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);
   digitalWrite(LedPinG, HIGH);
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   digitalWrite(LedPinG, LOW);
   
   duracion = pulseIn(EchoPin, HIGH);
   
   distanciaCm = duracion * 10 / 292/ 2;
   return distanciaCm;
}
