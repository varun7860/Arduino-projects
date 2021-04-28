# Self Balancing Robot
<img src="https://github.com/varun7860/Arduino-projects/blob/master/Self%20Balancing%20Robot/Images/Self%20Balancing%20Bot.jpg" width="522" height="555"/>

## Description 

I always wondered how awesome it would be if Robot balances itself on two wheels/legs just like us humans!. Cool isn't it? Yes you are right !! so I decided to build one for myself. So basically this is a self balancing robot that can balance itself on just two wheels. This Robot balances itself and can also withstand the weight of glass of water! how cool is that?!

## Applications

- It can be used in restaurants to serve food to customer just like waiters do today.
- They can also be used in hospitals to carry necessary medical supplies to patients autonomously.
- They can used in houses especially of old people to supply them with necessary needs.
- They can be used in malls for welcoming people entering the malls.

## Calibration Of MPU-6050:

- It is done for obtaining the offset values when the robot is in erect position. The robot is set parallel to ground plane.
This position of the robot is called balancing position. The set of offset values are then taken such as Ax, Ay, Az and Gx, Gy, Gz (accelerometer and gyroscope reference axis values).These values are kept as reference values.
- Whenever an external disturbing forces comes into play, new set of offset values with respect to reference axis will be formed.
- A feedback mechanism is provided which compares the new set of values with initial reference values. Thus the position of robot from balancing position is determined.
- The angle of tilt can be corrected by controlling dc gear motors/Bo Motors thereby maintaining balance.

## PID Conceptfor self balancing Robot

<img src="https://github.com/varun7860/Arduino-projects/blob/master/Self%20Balancing%20Robot/Images/PID.jpg" width="718" height="316"/>

1. PID stands for:

- P : Proportional
- I : Integral
- D: Derivative

2. Proportional:This is also called as proportional gain and denoted by "Kp".The proportional gain Kp is directly proportional to error. A small change in Kp would automatically be reflected in the error values. Small values of Kp would be insufficient, since the controller might not be able to minimise the error and quickly respond to the changes affecting the system. Large values of Kp cause the system to be unstable and result in weird oscillations.You can look at the image above for the formula of "Kp".

3. Integral: This is also called as integral gain and is denoted by "Ki".The integral gain Ki accounts for the past values of the error and integrates them over time to produce the Ki term. i.e., the integral term lets the controller to take up all the errors that are accumulating over time and creates the next Ki value depending on the previous errors.A larger Ki value results in higher growth of the accumulated error.You can look at the image above for the formula of "Ki".

4. Derivative: This is also called as Derivative gain and is denoted by "Kd"..The derivative gain Kd estimates the future trend of the error based on the current rate of change of error. i.e., it controls the error by analysing the rate of change of error. This helps to dampen the system, thus improving stability. The change in the system will be rapidly evident with smaller change in Ki.You can look at the image above for the formula of "Kd".

5. Error : it is the difference between the desired position and obtained position of the Robot. It is given by:

   - Error(E) = Desired_Position - Actual_Position

## Tuning Of PID Values 
- There are many ways by which Kp, Ki and Kd values of the system is tuned one of which is manual tuning through which stability can be easily achieved. Initially the Kp, Ki and Kd values are set to zero. Then Kp value is increased from zero till a point where the system starts to oscillate from its mean position.
- As the Kp value is increased, it was seen that response of the system increase gradually. Keeping the Kp value a constant the Ki value is then increased till a point where it is seen from the system that a small inclination towards a direction tends to accelerate the vehicle towards that direction. When the Kp and Ki values are properly obtained, then the Kd value is increased. The Kd value is increased such that rapid acceleration is reduced considerably.
- Proper KD value results in lesser overshoots and oscillations. After obtaining the rough Kp, Ki and Kd values a fine tuning is done. The above steps are repeated a number of times to obtain the best combination of gain value

## Working of Self balancing Robot:
- As soon as power is supplied to the Robot the mpu 6050 supplies the values of AX, AY, AZ, GX, GY, GZ to arduino.
- Arduino computes "Kp", "Ki" and "Kd" with the formulas mentioned above and calculates the absolute error between the desired position and position obtained.
- Depending upon the "Error" Robot moves forward or backward which results in balancing of the Robot.

## Code Explanation

1. Include the necessary libraries

```
#include "I2C.h"
#include <PID_v1.h> //From https://github.com/br3ttb/Arduino-PID-Library/blob/master/PID_v1.h
#include "MPU6050_6Axis_MotionApps20.h" //https://github.com/jrowberg/i2cdevlib/tree/master/Arduino/MPU6050

MPU6050 mpu; //Instance of MPU-6050 Class
double input, output;
PID pid(&input, &output, &setpoint, Kp, Ki, Kd, DIRECT); //Instance of PID Class.
```

2. Set the variables for PID of Self Balancing Robot.
```
double setpoint= 178.54; //This is desired point which we want robot to be always at.
double Kp = 100; //Set this first
double Kd = 1.5 ; //Set this secound
double Ki = 160; //Finally set this 
```

3. Set the variables for Digital Motion Processor on MPU-6050
```
ool dmpReady = false;  // set true if DMP init was successful
uint8_t mpuIntStatus;   // holds actual interrupt status byte from MPU
uint8_t devStatus;      // return status after each device operation (0 = success, !0 = error)
uint16_t packetSize;    // expected DMP packet size (default is 42 bytes)
uint16_t fifoCount;     // count of all bytes currently in FIFO
uint8_t fifoBuffer[64]; // FIFO storage buffer

// orientation/motion vars
Quaternion q;           // [w, x, y, z]         quaternion container
VectorFloat gravity;    // [x, y, z]            gravity vector
float ypr[3];           // [yaw, pitch, roll]   yaw/pitch/roll container and gravity vector

volatile bool mpuInterrupt = false;     // indicates whether MPU interrupt pin has gone high

void dmpDataReady()
{
    mpuInterrupt = true;
}
```

4. Initialize the modules in `void setup` Function.

```
void setup() {
  Serial.begin(115200);

  // initialize device
    Serial.println(F("Initializing I2C devices..."));
    mpu.initialize();

     // verify connection
    Serial.println(F("Testing device connections..."));
    Serial.println(mpu.testConnection() ? F("MPU6050 connection successful") : F("MPU6050 connection failed"));

    // load and configure the DMP
    devStatus = mpu.dmpInitialize();

    
    // supply your own gyro offsets here, scaled for min sensitivity
    mpu.setXGyroOffset(-106);
    mpu.setYGyroOffset(33);
    mpu.setZGyroOffset(-24);
    mpu.setZAccelOffset(9572); 

      // make sure it worked (returns 0 if so)
    if (devStatus == 0)
    {
        // turn on the DMP, now that it's ready
        Serial.println(F("Enabling DMP..."));
        mpu.setDMPEnabled(true);

        // enable Arduino interrupt detection
        Serial.println(F("Enabling interrupt detection (Arduino external interrupt 0)..."));
        attachInterrupt(0, dmpDataReady, RISING);
        mpuIntStatus = mpu.getIntStatus();

        // set our DMP Ready flag so the main loop() function knows it's okay to use it
        Serial.println(F("DMP ready! Waiting for first interrupt..."));
        dmpReady = true;

        // get expected DMP packet size for later comparison
        packetSize = mpu.dmpGetFIFOPacketSize();
        
        //setup PID
        pid.SetMode(AUTOMATIC);
        pid.SetSampleTime(10);
        pid.SetOutputLimits(-255, 255);  
    }
    else
    {
        // ERROR!
        // 1 = initial memory load failed
        // 2 = DMP configuration updates failed
        // (if it's going to break, usually the code will be 1)
        Serial.print(F("DMP Initialization failed (code "));
        Serial.print(devStatus);
        Serial.println(F(")"));
    }

//Initialise the Motor output pins
    pinMode (10, OUTPUT);
    pinMode (3, OUTPUT);
    pinMode (4, OUTPUT);
    pinMode (5, OUTPUT);
    pinMode (6,OUTPUT);
    pinMode(9,OUTPUT);
//By default turn off both the motors
    digitalWrite(10,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    analogWrite(6,0);
    analogWrite(9,0);    
}
```

5. Write the necessary function which will be used by the Robot. For basic self balancing bot ; `Forward`, `Backward` and `Stop` are the 3 main functions required.

```
void Forward() //Code to rotate the wheel forward 
{
    digitalWrite(10,LOW);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    analogWrite(6,output);
    analogWrite(9,output);
    Serial.print("F"); //Debugging information 
}

void Reverse() //Code to rotate the wheel Backward  
{
    digitalWrite(10,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW); 
    analogWrite(6,output*-1);
    analogWrite(9,output*-1);
    Serial.print("R");
}

void Stop() //Code to stop both the wheels
{
    digitalWrite(8,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW); 
    analogWrite(6,0);
    analogWrite(9,0);
    Serial.print("S");
}
```

6. In `void loop` check for any available interrupts for MPU-6050. If yes then compute the `PID` Value followed by the `Error` and then get the desired value ie `output`

```
void loop()
{
 
    // if programming failed, don't try to do anything
    if (!dmpReady) return;

    // wait for MPU interrupt or extra packet(s) available
    while (!mpuInterrupt && fifoCount < packetSize)
    {
        //no mpu data - performing PID calculations and output to motors     
        pid.Compute();   
        
        //Print the value of Input and Output on serial monitor to check how it is working.
        Serial.print(input); Serial.print(" =>"); Serial.println(output);
               
        if (input>150 && input<200)//If the Bot is falling 
        {
          
          if (output>0) //Falling towards front 
          {
          Forward(); //Rotate the wheels forward 
          }
          else if (output<0) //Falling towards back
          {
          Reverse(); //Rotate the wheels backward
          } 
        }
        else //If Bot not falling
        {
        Stop(); //Hold the wheels still
        }
        
    }

    // reset interrupt flag and get INT_STATUS byte
    mpuInterrupt = false;
    mpuIntStatus = mpu.getIntStatus();

    // get current FIFO count
    fifoCount = mpu.getFIFOCount();

    // check for overflow (this should never happen unless our code is too inefficient)
    if ((mpuIntStatus & 0x10) || fifoCount == 1024)
    {
        // reset so we can continue cleanly
        mpu.resetFIFO();
        Serial.println(F("FIFO overflow!"));

    // otherwise, check for DMP data ready interrupt (this should happen frequently)
    }
    else if (mpuIntStatus & 0x02)
    {
        // wait for correct available data length, should be a VERY short wait
        while (fifoCount < packetSize) fifoCount = mpu.getFIFOCount();

        // read a packet from FIFO
        mpu.getFIFOBytes(fifoBuffer, packetSize);
        
        // track FIFO count here in case there is > 1 packet available
        // (this lets us immediately read more without waiting for an interrupt)
        fifoCount -= packetSize;

        mpu.dmpGetQuaternion(&q, fifoBuffer); //get value for q
        mpu.dmpGetGravity(&gravity, &q); //get value for gravity
        mpu.dmpGetYawPitchRoll(ypr, &q, &gravity); //get value for ypr

        input = ypr[1] * 180/M_PI + 180;

   }
}
```

## Working Video

[![alt text][1]][2]

[1]: https://github.com/varun7860/Arduino-projects/blob/master/Self%20Balancing%20Robot/Images/Output%20Video.jpg
[2]: https://youtu.be/nb_hnOeazkE
