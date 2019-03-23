#include "../../includes/gpio_arduino.h"

int ledPin = 29;  //Correspond à la pin 40
int black = 0;    //Correspond à la pin 11
int red = 2;      //Correspond à la pin 13
int white = 3;    //Correspond à la pin 15



void setup()
{
	pinMode(ledPin,OUTPUT);
	pinMode(black, OUTPUT);
	pinMode(red, OUTPUT);
	pinMode(white, OUTPUT);
	cout << "Hello World" << endl;
	digitalWrite(black, LOW);
	digitalWrite(red, 500);
}

void loop()
{
	digitalWrite(ledPin,HIGH);
	delay(100);
	digitalWrite(ledPin,LOW);
	delay(100);
	cout << "Blink the LED" << endl;
}

void clear()
{
	pinClear(black);


}
