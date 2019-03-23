#ifndef GPIO_ARDUINO_H
# define GPIO_ARDUINO_H

# include <iostream>
# include <wiringPi.h>
# include <signal.h>

void setup();
void loop();
void clear();
void pinClear(int pin);

using namespace std;

#endif
