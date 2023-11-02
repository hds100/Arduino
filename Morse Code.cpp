// Code in C++

/*
Morse code

- When the LED flashes three times quickly: S
- When the LED flashes three times in a prolonged manner: O
- When the LED flashes three times quickly: S

Forming a request for help > S O S
  */
// This code configures digital pin 10 as OUTPUT on Arduino //
void setup()
{
  pinMode(10, OUTPUT); 
}
/* The "for" function creates a loop that runs as long as a comparison test is true

A variable x is declared as an int number and assigned the value 0
Then, it tests whether the value of x is less than 3 ---> If the test is true, the loop below is executed
  
If true, there are 3 quick flashes of the LED indicating S letter

In the second loop, the test is the same, however, the LED waiting time is longer, forming O letter

In the third, the first loop is repeated to form S letter again

  */
void loop() 
{ 
		for (int x=0; x<3; x++) 
		{ 
			digitalWrite (10, HIGH); // Red LED is ON
			delay (200); // Wait 200 milliseconds
			digitalWrite (10, LOW); // Red LED is off 
			delay (150); // Wait 150 milliseconds
		} 
		delay (500);// 500 millisecond interval between letters
		for (int x=0; x<3; x++) // Again the for loop while a comparison test is true
		{ 
			digitalWrite (10, HIGH); // Red LED is on
			delay (800); //  Wait 800 milliseconds
			digitalWrite (10, LOW); // Red LED is off
			delay (100); // Wait 100 miliseconds
		} 
		delay (500);// 500 millisecond interval between letters
		for (int x=0; x<3; x++) 
		{ 
			digitalWrite (10, HIGH); // Red LED is on 
			delay (200); // Wait 200 milliseconds
			digitalWrite (10, LOW); // Red LED is off
			delay (150); // Wait 150 milliseconds
		} 
			delay (5000); // Wait 5000 milliseconds to repeat the signal programming
}
