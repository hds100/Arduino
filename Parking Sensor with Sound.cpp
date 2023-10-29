// Code in C++
//

// Code in C
/*
Red LED = Port 13
Piezo = Port 5
Trigger Pin = Port 10
Echo Pin = Port 11
VCC = Positive
GND = Negative
*/
/*
Defining the distance variable that will be used next in a conditional (if) to define the situation in which the car must maintain distance
  */
int distancia = 0;

/*
Defining the distance variable to be read from the ultrasonic distance sensor on trig pin 10 and echo pin 11

The trig and echo pins are control pins, with trigger emitting ultrasonic sound waves and echo being the receiver
On this trigger pin will emit the waves and the echo will receive them, measuring the time taken for the waves to reach an object and return
*/

long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW); // The trigger pin is off = low
  delayMicroseconds(2); // Wait 2 microseconds because of delay
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH); // The trigger pin turns on and emits ultrasonic waves for 10 microseconds
  delayMicroseconds(10); // Wait 10 microseconds because of delay
  digitalWrite(triggerPin, LOW); // Turn it off
  pinMode(echoPin, INPUT); // The echo pin receives the waves
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH); // Here it reads the waves and returns their travel time in microseconds
}

// Defining the output ports of red LED and piezo in Arduino
void setup()
{
  pinMode(13, OUTPUT);
  pinMode(5, OUTPUT);
}

/*
  Here we use the distance variable with default value of the distance of the object in the sensor range
  It then multiplies by the travel value of the ultrasonic waves received by the echo pin
*/
void loop()
/*
Variable distance at standard value of 0.01723 miliseconds * reading of the echo pin in the time of receiving the ultrasonic waves
*/
{
  distancia = 0.01723 * readUltrasonicDistance(10, 11); 
  if (distancia < 50) { //If the distance is less than 50 cm
    digitalWrite(13, HIGH); // Red LED is on
    digitalWrite(5, HIGH); // Piezo emits sound
    delay(1000); // Wait for 1000 millisecond(s)
    digitalWrite(5, LOW); // Piezo is off
  } else { // If the distance is greater than 50 cm
    digitalWrite(13, LOW); // Red LED is off
    digitalWrite(5, LOW);  // Piezo is off
  }
}
