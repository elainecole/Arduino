void setup()                                 // Built-in initialization block
{
                              // Delay to finish tone
  pinMode(7, INPUT);                         // Set right whisker pin to input
  pinMode(5, INPUT);                         // Set left whisker pin to input  
  pinMode(8, OUTPUT);
  pinMode(2, OUTPUT);
  Serial.begin(9600);                        // Set data rate to 9600 bps
}  
 
void loop()                                  // Main loop auto-repeats
{                                            
  byte wLeft = digitalRead(5);               // Copy left result to wLeft  
  byte wRight = digitalRead(7);              // Copy right result to wRight

  if(wLeft == 0)              // If left whisker contact
  {
    digitalWrite(8, HIGH);    // Left LED on
  }
  else                        // If no left whisker contact
  {
    digitalWrite(8, LOW);     // Left LED off
  }

  if(wRight == 0)             // If right whisker contact
  {
    digitalWrite(2, HIGH);    // Right LED on
  }
  else                        // If no right whisker contact
  {
    digitalWrite(2, LOW);     // Right LED off
  }
  Serial.print(wLeft);                       // Display left whisker state
  Serial.println(wRight);                    // Display right whisker state

  delay(50);                                 // Pause for 50 ms
}    
