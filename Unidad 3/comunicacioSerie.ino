boolean v1=false; 
boolean v2=false;

int numero1=0; 
int numero2=0;

void setup() {
  Serial.begin(9600);
  delay(1000); 
  Serial.print("Ingrese dos numeros");

}

void loop() { 
  if(v1 && v2){
    Serial.print("\nLa suma es "); 
    Serial.print(numero1+numero2); 
    v1=false; v2=false; 
    }
    } 
    void serialEvent(){
      while(Serial.available()){
        if(!v1){ 
          numero1=Serial.readString().toInt(); 
          Serial.print("\nPrimer numero:"); 
          Serial.print(numero1); v1=true; 
          }
          else{ 
            if(!v2){
              numero2=Serial.readString().toInt();
              Serial.print("\nSegundo numero:"); 
              Serial.print(numero2); v2=true; 
              } 
           } 
       } 
   }
