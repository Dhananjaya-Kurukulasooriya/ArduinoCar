
char readValue;
void setup() {
  Serial.begin(38400);
  Serial.setTimeout(100);
}

void loop() {
  if(Serial.available())
  {
    readValue=Serial.read();
    Serial.println(readValue); 
    
   }
   

}
