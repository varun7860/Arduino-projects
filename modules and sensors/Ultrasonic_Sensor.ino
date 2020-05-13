//Ultrasonic sensor HC-SR04 is used here to measure distance in range of 2cm-400cm with accuracy of 3mm. 
//The sensor module consists of ultrasonic transmitter, receiver and the control circuit. 
//The working principle of ultrasonic sensor is as follows:

//1.High level signal is sent for 10us using Trigger.
//2.The module sends eight 40 KHz signals automatically, and 
//then detects whether pulse is received or not.
//3.If the signal is received, then it is through high level. 
//The time of high duration is the time gap between sending and 
//receiving the signal.


int echoPin =7;
int trigpin=8;
int duration;
int distance;


void setup() 
{
pinMode(trigpin, OUTPUT);
pinMode(echoPin, INPUT);
Serial.begin(9600);  
}

void loop()
{
 digitalWrite(trigpin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigpin, LOW);
 delayMicroseconds(10);
 digitalWrite(trigpin, HIGH);
 duration= pulseIn(echoPin, HIGH);
 distance= (duration/2)/29.1; 
 Serial.print("distance: ");
 Serial.println(distance);
 delay(1000);
}
