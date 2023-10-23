// Code in C++
//

/*
  LED lamp output configuration

13 = Green
5 = Yellow
1 = Red
  */
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(1, OUTPUT);
}
/*
On and off loop configuration at exit doors, following the logical sequence of Brazilian traffic lights

Note: the seconds in which a lamp waits to turn off are approximate!

Green = 8 seconds
Yellow = 4 seconds
Red = 8 seconds

High = on
Low = off
  */
void loop()
{
  digitalWrite(13, HIGH);
  delay(8000); // Wait for 8000 millisecond(s)
  digitalWrite(13, LOW);
  digitalWrite(5, HIGH);
  delay(4000); // Wait for 4000 millisecond(s)
  digitalWrite(5, LOW);
  digitalWrite(1, HIGH);
  delay(8000); // Wait for 8000 millisecond(s)
  digitalWrite(1, LOW);
}
