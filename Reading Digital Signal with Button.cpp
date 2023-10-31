// Code in C++

void setup() 
{ 
 Serial.begin (9600); // Defining function that will be used when working with serial communication. 9600 = communication in bits per second (baud rate)
 pinMode (2, INPUT); // Setting the button pin output 
} 
/*
Reading an digital signal on the computer

Reading an digital value (0 or 1) 
When the button is not pressed, it remains in the state of 0 and when the button is pressed, it changes to 1 (the values are shown on the serial monitor)
  */
void loop() 
{ 
 int sensorValue = digitalRead(2); // This line defines the variable sensorValue and stores the value of digital port 2 in the variable
 Serial.println (sensorValue, DEC); // Shows the serial value on the serial monitor
 delay (1000); 
} 
