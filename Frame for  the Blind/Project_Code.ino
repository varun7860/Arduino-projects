/*This is the final code of the project: Obstacle Detection for the Blind.
If you have any doubts refer the project description.md file of this
Project.*/

int Trigpin = 5; // Any digital I/O Pin can be used here
int Echopin = 4; // Any digital I/O Pin can be used here
const int buzzer= 10; // Any digital I/O Pin can be used here
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
