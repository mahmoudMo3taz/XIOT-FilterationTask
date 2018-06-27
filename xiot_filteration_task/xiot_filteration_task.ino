int tempraturePin=0;
int ledPin=13;
int interruptPin=2;
int state=1;
void setup() {
  pinMode(ledPin,OUTPUT);
  //pinMode(interruptPin,INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), pressed, CHANGE);
  Serial.begin(9600);
}

void loop() {
  float voltage ,temprature;
  voltage=getVoltage(tempraturePin);
  temprature=(voltage-0.5)*100.00;
  Serial.println(voltage);
  Serial.println(temprature);
  delay(3000);
  //to repeat every 3 second
 digitalWrite(ledPin, state);
  
}
//this function to convert from 0 to 1023 that come from analog reat function to 0to5 volt
float getVoltage(int pin){
  return (analogRead(pin)*0.0048821814);  
  
  }
  void pressed(){
    Serial.println("Pressed");
   state = !state;
     if(state==0){
    Serial.println("State Now IS : OFF");
   }
  else if(state==1){
    Serial.println("State Now IS : ON");
    }
  
    }
