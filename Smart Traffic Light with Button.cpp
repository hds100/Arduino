// Code in C++
//

/*
  Configuration of LED and Button output ports

  11 = Green
  12 = Yellow
  13 = Red
  7 = Red (pedestrian)
  6 = Green (pedestrian)
  8 = Button (button for stop traffic lighting)


*/
void setup()
{
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(8, INPUT);
}
/*
11 - Green = ON
7 - Red (pedestrian) = ON

If = When the pedestrian presses the button, the traffic light for vehicles from green (11) changes to yellow (gate 12), and then to red (13)
For pedestrians, it changes to green (gate 6), a descent that can cross the lane

Wait 30 seconds

Loop back to initial situation = green for vehicles and red for pedestrians

  */
void loop()
{
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  if (digitalRead(8) == 0) {
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    delay(3000); // Wait for 3000 millisecond(s)
    digitalWrite(12, LOW);
    digitalWrite(7, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(13, HIGH);
    delay(6000); // Wait for 6000 millisecond(s)
    digitalWrite(13, HIGH);
    delay(3000); // Wait for 3000 millisecond(s)
    digitalWrite(13, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
  }
}
