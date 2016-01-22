void setup() {
  // put your setup code here, to run once:
pinMode(13, OUTPUT); 
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(13, HIGH);                    // Pin 13 = 5 V, LED emits light
  delay(170);                                // ..for 0.17 seconds
  digitalWrite(13, LOW);                     // Pin 13 = 0 V, LED no light
  delay(1830); 
}
