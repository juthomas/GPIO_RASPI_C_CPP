#include <wiringPi.h>
#include <stdio.h>

int ledPin = 29;  //Correspond à la pin 40
int black = 0;
int red = 2;
int white = 3;

void setup(){

	pinMode(black, OUTPUT);
	pinMode(red, OUTPUT);
	pinMode(white, OUTPUT);
	pinMode(ledPin,OUTPUT);
	printf("Hello World\n");
	digitalWrite(black, LOW);
	digitalWrite(red, 500);
}

void loop(){
	digitalWrite(ledPin,HIGH);
	delay(100);
	digitalWrite(ledPin,LOW);
	delay(100);

	printf("Blink the LED\n");
}

int main(void)//(int argc, char **argv)
{
	if(wiringPiSetup()<0){

	printf("setup wiring pi failed\n");
		return 1;
	}
	setup();
	while(1){
		loop();
	}
	
	return 0;
}
