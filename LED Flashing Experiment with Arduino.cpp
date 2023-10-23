// Code in C++  //

// This code configures digital pin 10 as OUTPUT on Arduino //

void setup()
{
  pinMode(10, OUTPUT);
}

/* Here the state changes in a loop between HIGH and LOW 
High = on
Wait 2 seconds
Low = off
*/

void loop()
{
  digitalWrite(10, HIGH);
  delay(2000); // Wait for 2000 millisecond(s)
  digitalWrite(10, LOW);
  delay(2000); // Wait for 2000 millisecond(s)
}
