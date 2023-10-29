// Code in C++
/*
Reading an analog signal on the computer

Reading an analog value (0 to 1023) provided by a potentiometer, sending it via serial communication to the computer.
Serial communication on the computer is seen on a separate screen in a serial monitor.
  */
void setup() 
{ 
 Serial.begin (9600);  // Defining function that will be used when working with serial communication. 9600 = communication in bits per second (baud rate)
} 
void loop() 
{ 
 int sensorValue = analogRead (A0); // This line defines the variable sensorValue and stores the value of analog port 0 in the variable
 Serial.println (sensorValue, DEC); // Shows the serial value on the serial monitor
 delay (1000);
}
