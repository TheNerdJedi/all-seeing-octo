#include <Ultrasonic.h>
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 
                // a maximum of eight servo objects can be created 
 int p = 13;
int pos = 0;    // variable to store the servo position 
int value =0; 
Ultrasonic ultrasonic(8,12);


void setup() {
pinMode(p, INPUT);  
myservo.attach(9);
Serial.begin(9600);

}

void loop()
{
  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);       // waits 15ms for the servo to reach the position 
    double reading = ultrasonic.Ranging(INC);
    Serial.println(reading); 
    delay(1);
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);
    double reading = ultrasonic.Ranging(INC);
    Serial.println(reading); 
    delay(1);
  }
 double reading = ultrasonic.Ranging(INC);
 Serial.println(reading); 
    delay(1);
   
  
}




