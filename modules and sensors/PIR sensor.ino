//under normal condition where there is no movement in front of the sensor, both the slots in the Sensor detect same amount of infrared radiation.
//When there is movement in front of the sensor, like a human or a cat, their radiation is interpreted by one of the slots first and the differential output between the two slots becomes positive.
//As the person moves away, the second slot detects the radiation and the differential output will become negative. Based these output pulses, a motion is detected.
//On the top of sensor board, there is a special type of lens called Fresnal Lens that is covering up the actual Pyroelectric Sensor. The job of the Fresnal Lens is to focus all the infrared radiation onto the pyroelectric sensor.
 //if you look at the back of the PIR Sensor board, the whole circuitry is housed there. The brain of the PIR Sensor Module is the BISS0001 PIR Motion Detector IC. Near this IC, we have two potentiometers, one for adjusting the Sensitivity and the other is for adjusting the delay time.
//Using Sensitivity Adjust, you can control the range of field of view and in our sensor, it is up to 7 meters. Using the Delay Time Adjust, you can control the duration for which the Digital Out will stay HIGH when a moving object is detected.   
//Compact size (28 x 38 mm)

//Supply current: DC5V-20V(can design DC3V-24V)

//Current drain :< 50uA (Other choice: DC0.8V-4.5V; Current drain: 1.5mA-0.1mA)

//Voltage Output: High/Low level

//signal ï¼š3.3V (Other choice: Open-Collector Output) TTL output High sensitivity

//Delay timeï¼š5s-18 minute

//Blockade timeï¼š0.5s-50s (acquiescently 0 seconds)

//Operation Temperature: -15oC -70Oc

//Infrared sensor: dual element, low noise, high sensitivity


//int Led = 13;
int buzz = 13;                // the pin that the buzzer is atteched to
int sensor = 2;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

void setup() 
{
  pinMode(buzz, OUTPUT);      // initalize LED as an output
  pinMode(sensor, INPUT);    // initialize sensor as an input
  Serial.begin(9600);        // initialize serial
}

void loop()
{
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) 
  {           // check if the sensor is HIGH
    digitalWrite(buzz, HIGH);   // turn LED ON
    delay(100);                // delay 100 milliseconds 
    
    if (state == LOW) 
    {
      Serial.println("Motion detected!"); 
      state = HIGH;       // update variable state to HIGH
    }
  } 
  else 
  {
      digitalWrite(buzz, LOW); // turn LED OFF
      delay(200);             // delay 200 milliseconds 
      
      if (state == HIGH)
      {
        Serial.println("Motion stopped!");
        state = LOW;       // update variable state to LOW
    }
  }
}
