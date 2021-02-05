//The L293D is a 16-pin Motor Driver IC which can control a set of two DC motors simultaneously in any direction.
//The L293D is designed to provide bidirectional drive currents of up to 600 mA (per channel) at voltages from 4.5 V to 36 V (at pin 8!). 
//You can use it to control small dc motors - toy motors. 

//The const keyword stands for constant. 
//It is a variable qualifier that modifies the behavior of the variable, making a variable "read-only". 
//This means that the variable can be used just as any other variable of its type, but its value cannot be changed. 
//You will get a compiler error if you try to assign a value to a const variable.

// For Motor A
int MotorPin1 = 3;
int MotorPin2 = 4;
//int ENA =10;

//For Motor B
int MotorPin3 = 5;
int MotorPin4 = 6;
//int ENB = 9;


//For Ultrasonic Sensor
int TrigPin = 8;
int EchoPin = 7;

//define input and output in void setup 
void setup() 
{
 pinMode(MotorPin1, OUTPUT); 
 pinMode(MotorPin2, OUTPUT);
 pinMode(MotorPin3, OUTPUT);
 pinMode(MotorPin4, OUTPUT);
 //pinMode(ENA1, OUTPUT);
 //pinMode(ENA2, OUTPUT);
 pinMode(TrigPin, OUTPUT);
 pinMode(EchoPin, INPUT);
 //Serial.begin(9600);
 //digitalWrite(ENA1,HIGH);
 //digitalWrite(ENA2, HIGH);
}

void loop() 
{
 long duration, distance;
 digitalWrite(TrigPin, HIGH);
 delayMicroseconds(1000);
 digitalWrite(TrigPin, LOW);
 //delayMicroseconds(10);
// digitalWrite(TrigPin, HIGH);
 duration= pulseIn(EchoPin, HIGH);
 distance= (duration/2)/29.1; 
 delay(10);
 
 
    if((distance>25))
   {
    delay(100);
    digitalWrite(MotorPin1, LOW);
    digitalWrite(MotorPin2, LOW);
    digitalWrite(MotorPin3, LOW);
    digitalWrite(MotorPin4, LOW);
   }

    else if((distance<25))
   {
    delay(100);
    digitalWrite(MotorPin1, HIGH);
    digitalWrite(MotorPin2, LOW);
    digitalWrite(MotorPin3, HIGH);
    digitalWrite(MotorPin4, LOW);
    //analogWrite(ENA1, HIGH);
    //analogWrite(ENA2, HIGH);
   }

     else if(distance<7)
    {
      delay(200);
      digitalWrite(MotorPin1, LOW);
      digitalWrite(MotorPin2, HIGH);
      digitalWrite(MotorPin3, LOW);
      digitalWrite(MotorPin4, HIGH);
      //analogWrite(ENA1, HIGH);
      //analogWrite(ENA2, HIGH);
    }
    //if(distance<3&&distance>1)
    //{
    //  delay(500);
     // digitalWrite(MotorPin1, LOW);
     // digitalWrite(MotorPin2, LOW);
      //digitalWrite(MotorPin3, LOW);
      //digitalWrite(MotorPin4, LOW);
    //}
  }
