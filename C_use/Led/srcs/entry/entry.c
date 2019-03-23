#include <wiringPi.h>
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

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
	printf("Hello World\n");
	digitalWrite(black, LOW);
	digitalWrite(red, 500);
}

void loop()
{
	digitalWrite(ledPin,HIGH);
	delay(100);
	digitalWrite(ledPin,LOW);
	delay(100);
	printf("Blink the LED\n");
}

void clear_gpio (int sig)
{
	printf("Signal : %d\n", sig);
	printf("Cleaning used Gpio\n");
	pinMode(ledPin, INPUT);
	pinMode(black, INPUT);
	pinMode(red, INPUT);
	pinMode(white, INPUT);
	exit(1);
}

int main(void)//(int argc, char **argv)
{
	//signal(SIGQUIT, clear_gpio);
	signal(SIGINT, clear_gpio);
	if(wiringPiSetup() < 0)
	{
		printf("Setup wiringPi failed\n");
		return (1);
	}
	setup();
	while(1)
	{
		loop();
	}
	clear_gpio(0);
	return (0);
}

