int Trigpin = 5;
int Echopin = 4;
const int buzzer= 10;
long duration;
int distance;

void setup() 
{
 Serial.begin(9600);
 pinMode(Echopin,INPUT);
 pinMode(Trigpin,OUTPUT);
 pinMode(buzzer,OUTPUT);

}

void loop() 
{
  digitalWrite(Trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(Trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(Trigpin, LOW);
  
  duration = pulseIn(Echopin,HIGH);
  distance = (duration*0.034)/2;
  Serial.println(distance);
  delay(200);
  
  if (distance<30&&distance>1)
  {
    digitalWrite(buzzer,HIGH);
    delay(3000);
    digitalWrite(buzzer,LOW);
  }

  else
  {
    digitalWrite(buzzer,LOW);
  }
}
