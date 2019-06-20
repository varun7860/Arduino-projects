 char data =0;
 
void setup()
{
 pinMode(12,OUTPUT);
 Serial.begin(9600);
}

void loop() 
{
  if(Serial.available()>0)
  {
  data = Serial.read();
  Serial.print(data);
  digitalWrite(12, HIGH);
}
 if (data == '0')
 {
  digitalWrite(12, LOW);
    {
      Serial.println("12 :off");
    
    }
 }
  else if(data == '1')
  {
    digitalWrite(12, HIGH);
    
    {
      Serial.println("12: on");
     
    }
  }
}
  

