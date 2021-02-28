#include <Servo.h>

class Smart_Segregator
{
  public:
     int servo_pin;
     int moisture_sensor_pin;
     int touch_sensor_pin;
     int detect_moisture;
     int detect_touch;
 
     Servo servo;

     Smart_Segregator(int servo, int moisture, int touch)
     {
       servo_pin = servo;
       moisture_sensor_pin = moisture;
       touch_sensor_pin = touch;

       detect_moisture = 0;
       detect_touch = false;
     }

    void init()
    {
      Serial.begin(9600);
      servo.attach(servo_pin);
      servo.write(90);
      
      pinMode(moisture_sensor_pin, INPUT);
      pinMode(touch_sensor_pin, INPUT);

      Serial.println("Your Smart Segregator is ready to Segregate!");
    }

    void dry_waste()
    {
      servo.write(0);
    }

    void wet_waste()
    {
      servo.write(180);
    }

    void neutral_state()
    {
      servo.write(90);
    }
    
    void execute()
    {
      detect_moisture = digitalRead(moisture_sensor_pin);
      detect_touch = digitalRead(touch_sensor_pin);

      if (detect_moisture > 85 && detect_touch == true)
      {
        wet_waste();
      }

      else if (detect_moisture <= 85 && detect_touch == true)
      {
        dry_waste();
      }

      else 
      {
        neutral_state();
      }
    }
}

segregator = Smart_Segregator(8,6,2);

void setup() 
{
  segregator.init();
}

void loop() 
{
 segregator.execute();
}
