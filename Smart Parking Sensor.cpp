// Code in C
/*
Red LED = Port 10
Green LED = Port 12
Trigger Pin = Port 6
Echo Pin = Port 7
VCC = Positive
GND = Negative
*/
/*
Defining the distance variable that will be used next in a conditional (if) to define the situation in which the car must maintain distance
  */
int distance = 0;
/*
Defining the distance variable to be read from the ultrasonic distance sensor on trig pin 6 and echo pin 7

The trig and echo pins are control pins, with trigger emitting ultrasonic sound waves and echo being the receiver
On this trigger pin will emit the waves and the echo will receive them, measuring the time taken for the waves to reach an object and return

*/
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW); // The trigger pin is off = low
  delayMicroseconds(2); // Wait 2 microseconds because of the delay
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH); // The trigger pin turns on and emits ultrasonic waves for 10 microseconds
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW); // Turn it off
  pinMode(echoPin, INPUT); // The echo pin receives the waves
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH); // Here it reads the waves and returns their travel time in microseconds 
}
// Defining the output ports of the red and green LEDs on the Arduino
void setup()
{
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);
}
/*
  Here we use the distance variable with default value of the distance of the object in the sensor range
  It then multiplies by the travel value of the ultrasonic waves received by the echo pin
*/
void loop()
{
 /*
Variable distance at standard value of 0.01723 miliseconds * reading of the echo pin in the time of receiving the ultrasonic waves
*/
  distance = 0.01723 * readUltrasonicDistance(6, 7); 
  if (distance <= 50) { // If the distance variable is less than or equal to 50 cm, the red LED is on
    digitalWrite(10, HIGH);
    digitalWrite(12, LOW);
  } else { // Else, the green LED is on
    digitalWrite(12, HIGH);
    digitalWrite(10, LOW);
  }
  delay(10); // Delay a little bit to improve simulation performance
}
