/* */

#include <Servo.h>
#include <paj7620.h>

class Electronic_Mask
{
  /*
   _____________________________________________________________
  |
  | Description
  | -----------
  | - Used for operating Covid_19 Electronic Mask.
  |
  |.............................................................
  |
  | Attributes
  | ----------
  | pin_1 : int
  |    -  Left servo motor signal pin number on Arduino.
  |
  | pin_2 : int
  |    -  Right servo motor signal pin nimber on Arduino.
  |
  |............................................................
  |
  | Methods
  | -------
  | set_mask()
  |       - Attaches the servo to the PWM pin.
  |
  | turn_up()
  |       - Turns on the servo motor.
  |
  | turn_down()
  |       - Detaches servo motor and turns it off.
  |
  | turn_off()
  |       - Turns off the mask.
  |
  | execute()
  |       - Executes the mask in gesture controlled mode.
  |____________________________________________________________
  */
  
  public:
     //servo pins
     int servo_pin_1;
     int servo_pin_2;

     //Gesture constants
     uint8_t fault;
     uint8_t data;
     int GES_REACTION_TIME;
     int GES_ENTRY_TIME;
     int GES_QUIT_TIME;
     String gesture;
     String command;

     //servo instances
     Servo servo_1; // Left Servo
     Servo servo_2; // Right Servo
     
     Electronic_Mask(int pin_1, int pin_2)
     {
      servo_pin_1 = pin_1;
      servo_pin_2 = pin_2;

      GES_REACTION_TIME = 500;
      GES_ENTRY_TIME = 800;
      GES_QUIT_TIME = 1000;
      fault = 0;
      gesture = "";
     }

     void set_mask()
     {
       /*
        _____________________________________________________________
       |
       | Description
       | -----------
       | - Sets the mask to its initial position.
       |
       |.............................................................
       |
       | Attributes
       | ----------
       |  None
       |............................................................
       |
       | Returns
       | -------
       |  None
       |_____________________________________________________________
       */
       
      Serial.begin(9600);
      servo_1.attach(servo_pin_1, 500, 2500);
      servo_2.attach(servo_pin_2, 500, 2500);

      servo_1.write(90);
      servo_2.write(90);

      fault = paj7620Init();

      if(fault)
       {
        Serial.println("Error occured while initialising the mask: ");
        Serial.println(fault);
       }
      
      else
       {
        Serial.print("Mask Initilized: ");
        Serial.println("Your mask is ready to be operated by hand gestures!");
       }
     }
     
     void turn_up()
     {
        /*
        _____________________________________________________________
       |
       | Description
       | -----------
       | - Turns the mask up.
       |
       |.............................................................
       |
       | Parameters
       | ----------
       |  None
       |............................................................
       |
       | Returns
       | -------
       |  None
       |_____________________________________________________________
       */
       
      servo_1.write(90);
      servo_2.write(90);
     }

     void turn_down()
     {
       /*
        _____________________________________________________________
       |
       | Description
       | -----------
       | - Turns the mask down.
       |
       |.............................................................
       |
       | Parameters
       | ----------
       |  None
       |............................................................
       |
       | Returns
       | -------
       |  None
       |_____________________________________________________________
       */
       
      servo_1.write(150);
      servo_2.write(30);
     }

     void turn_off()
     {
       /*
        _____________________________________________________________
       |
       | Description
       | -----------
       | - Turns off the mask. To turn on the mask again press reset
       |   pin on the Arduino.
       |
       |.............................................................
       |
       | Parameters
       | ----------
       |  None
       |............................................................
       |
       | Returns
       | -------
       |  None
       |_____________________________________________________________
       */
       
      servo_1.detach();
      servo_2.detach();
     }

     String detect_gesture()
     {
       /*
        _____________________________________________________________
       |
       | Description
       | -----------
       | - Detects the gestures made by the user. This gesture detects
       |   two gestures: i) Up and ii) Down
       |
       |.............................................................
       |
       | Parameters
       | ----------
       |  None
       |............................................................
       |
       | Returns
       | -------
       |  String -> gesture
       |       - Gesture(Up or Down) in string format is returned.
       |_____________________________________________________________
       */
       
      data = 0;
      fault = 0;

      fault = paj7620ReadReg(0x43, 1, &data);

      if(!fault)
      {
      switch(data)
        {
          case GES_UP_FLAG:
             delay(GES_ENTRY_TIME);
             paj7620ReadReg(0x43, 1, &data);
             if (data == GES_FORWARD_FLAG)
               {
                gesture = "FORWARD";
                delay(GES_QUIT_TIME);
               }
             else if( data == GES_BACKWARD_FLAG)
               {
                gesture = "BACKWARD";
                delay(GES_QUIT_TIME);
               }

             else
             {
               gesture = "UP";
             }
             break;

          case GES_DOWN_FLAG:
             delay(GES_ENTRY_TIME);
             paj7620ReadReg(0x43, 1, &data);
             if (data == GES_FORWARD_FLAG)
               {
                gesture = "FORWARD";
                delay(GES_QUIT_TIME);
               }
             else if( data == GES_BACKWARD_FLAG)
               {
                gesture = "BACKWARD";
                delay(GES_QUIT_TIME);
               }

             else
             {
               gesture = "DOWN";
             }
             break;
         }
      }
      return gesture;
    }

     void operate()
     {
       /*
        _____________________________________________________________
       |
       | Description
       | -----------
       | - Starts the mask.
       |
       |.............................................................
       |
       | Parameters
       | ----------
       |  None
       |............................................................
       |
       | Returns
       | -------
       |  None
       |___________________________________________________________
       */
       
       command = detect_gesture();
       if(command == "UP")
       {
          turn_up();
       }

       else if(command == "DOWN")
       {
          turn_down();
       }
     }
};


//Declare the class object here.
Electronic_Mask mask(3,5);

void setup() 
{ 
  mask.set_mask();
}

void loop() 
{
  mask.operate();
}
