 char data =0; // char is a  data type used to store a character value. The size of the char datatype is at least 8 bits. 
(//Syntax
//char var = val;)
 
void setup()
{
 pinMode(12,OUTPUT);
 Serial.begin(9600); //9600 is the baud Rate
}

void loop() 
{
  if(Serial.available()>0) (//Serial.available() returns the number of characters (i.e. bytes of data) 
                           //which have arrived in the serial buffer and that are ready to be read.)
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
  

