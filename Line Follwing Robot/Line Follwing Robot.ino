int IR1 = 7;
int IR2 = 8;
int Led = 13;
int M1 = 2;
int M2 = 3;
int M3 = 4;
int M4 = 5;
int ENA = 9;
int ENB = 10;

void setup()
{
 pinMode(7, INPUT);
 pinMode(11, INPUT);
 pinMode(M1, OUTPUT);
 pinMode(M2, OUTPUT);
 pinMode(M3, OUTPUT);
 pinMode(M4, OUTPUT);
 //pinMode(ENA, OUTPUT);
 //pinMode(ENB, OUTPUT);
}

void forward()
{
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
  //analogWrite(ENA , 255);
  //analogWrite(ENB , 255);
}

void pause()
{
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(M4, LOW);
 // analogWrite(ENA , 0);
  //analogWrite(ENB , 0);
}

void right()
{
  digitalWrite(M1, LOW);
  digitalWrite(M2, HIGH);
  digitalWrite(M3, LOW);
  digitalWrite(M4, LOW);
  //analogWrite(ENA , 255);
  //analogWrite(ENB , 0);
}

void left()
{
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(M3, LOW);
  digitalWrite(M4, HIGH);
  //analogWrite(ENA , 0);
  //analogWrite(ENB , 255);
}


void loop()
{
  int detect1 = digitalRead(7);
  int detect2 = digitalRead(11);

  if(detect1==LOW && detect2==LOW)
  {
   
    forward();
    
  }

  if(detect1==HIGH &&detect2==HIGH)
  {
    pause();
  }

  if(detect1==LOW && detect2==HIGH)
  {
    right();
  }

  if(detect1==HIGH && detect2==LOW)
  {
    left();
  }
}
