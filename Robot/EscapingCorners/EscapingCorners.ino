#include <Servo.h>                           
 
Servo servoLeft;                            
Servo servoRight;
Servo servoHead;
Servo ping;


byte wLeftOld; // Previous loop whisker values
byte wRightOld;                              
byte counter; // For counting alternate corners
unsigned int duration;
unsigned int inches;
void setup()                                 
{
  pinMode(7, INPUT); // right whisker pin
  pinMode(5, INPUT); // left whisker pin  
  pinMode(8, OUTPUT); // Left LED indicator
  pinMode(2, OUTPUT); // Right LED indicator 
  //pinMode(9, INPUT); // PING 

  //tone(4, 3000, 1000); // Play tone for 1 second
 // delay(1000);     // Delay to finish tone

  servoLeft.attach(13);  // left signal
  servoRight.attach(12); // right signal
  servoHead.attach(11);  // head
  ping.attach(10);
  
  //init. prev states / counter
  wLeftOld = 0;  
  wRightOld = 1;  
  counter = 0;  
}  
 
void loop() // Main loop auto-repeats
{
  servoHead.write(180);   // Rotate servo counter clockwise
  delay(2000);          // Wait 2 seconds
  servoHead.write(0);     // Rotate servo clockwise
  delay(2000);
  servoHead.write(90);    // Rotate servo to center
  delay(2000); 
  return;
  // corner escape
  byte wLeft = digitalRead(5);  // Copy right result to wLeft  
  byte wRight = digitalRead(7); // Copy left result to wRight

  if(wLeft != wRight) // One whisker pressed?
  {  
    // Alternate from last time?
    if ((wLeft != wLeftOld) && (wRight != wRightOld))  
    {                                       
      counter++; 
      wLeftOld = wLeft;
      wRightOld = wRight;
      if(counter == 3) // Stuck in a corner?
      {
        wLeft = 0;  // Set up for U-turn
        wRight = 0;
        counter = 0;  // Clear 
      }
    }  
    else // Not alternate from last time
    {
      counter = 0; // Clear alternate corner count
    }
  }  

  // Whisker Navigation
  if((wLeft == 0) && (wRight == 0)) // If both whiskers contact
  {
    backward(1000); // Back up 1 second
    turnLeft(800);  // Turn left about 120 degrees
  }
  else if(wLeft == 0) // If only left whisker contact
  {
    backward(1000); // Back up 1 second
    turnRight(400);  // Turn right about 60 degrees
  }
  else if(wRight == 0) // If only right whisker contact
  {
    backward(1000); // Back up 1 second
    turnLeft(400); // Turn left about 60 degrees
  }
  else // Otherwise, no whisker contact
  {
    forward(20); // Forward 1/50 of a second
  }
}

void forward(int time)
{
  servoLeft.writeMicroseconds(1700);// Left wheel counterclockwise
  servoRight.writeMicroseconds(1300);// Right wheel clockwise
  delay(time); 
}

void turnLeft(int time)
{
  servoLeft.writeMicroseconds(1300); // Left wheel clockwise
  servoRight.writeMicroseconds(1300); // Right wheel clockwise
  delay(time); 
}

void turnRight(int time)
{
  servoLeft.writeMicroseconds(1700); // Left wheel counterclockwise
  servoRight.writeMicroseconds(1700); // Right wheel counterclockwise
  delay(time); 
}

void backward(int time)  
{
  servoLeft.writeMicroseconds(1300); // Left wheel clockwise
  servoRight.writeMicroseconds(1700);// Right wheel counterclockwise
  delay(time);
}
