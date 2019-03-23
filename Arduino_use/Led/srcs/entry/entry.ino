
#include "../../includes/gpio_arduino.h"




void pinClear(int pin)
{
	pinMode(pin, INPUT);
}

void clear_gpio(int sig)
{
//	cout << "Signal : " << sig << endl;
	cout << "Cleaning used Gpio" << endl;
	clear();
	exit(1);
}

int main(void)//(int argc, char **argv)
{
	signal(SIGINT, clear_gpio);
	if (wiringPiSetup() < 0)
	{
		cout << "Setup wiringPi failed" << endl;
		return(1);
	}
	setup();
	while (1)
	{
		loop();
	}
	clear_gpio(0);
	return(0);
}
