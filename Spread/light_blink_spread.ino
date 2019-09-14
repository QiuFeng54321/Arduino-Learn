#include <Arduino.h>
#include "../User_Setup.h"
#include "../HDR.hpp"

const int portAmount = 8, start_port = 3, light_delay = 400;

//Generate ports from 3 to 9
int *ports = new int[portAmount]{7, 6, 8, 5, 9, 4, 10, 3};

//Generate ports from middle to the most apart
//int *middle;

//Current port index
int current_port = 0;

////Is it now blinking forward or backward?
////If it is blinking positive(from start_port to start_port+portAmount), it is true.
////Otherwise it is false.
//bool blink_direction = true;

int last_light1, last_light2;

void setup() {
//	ports = generatePorts(start_port, portAmount);
	//Initialise pinModes
	for (int i = 0; i < portAmount; i++) {
		pinMode(ports[i], OUTPUT);
	}
//	middle = midSort(ports, portAmount);
//
//	for (int gp = 0; gp < portAmount; gp++) {
////		printf("Port %d is %d \n", gp, ports[gp]);
//		Serial.print("Port ");
//		Serial.print(gp);
//		Serial.print(" is ");
//		Serial.println(middle[gp]);
//	}
}

void loop() {
	digitalWrite(ports[last_light1], LOW);
	digitalWrite(ports[last_light2], LOW);
	digitalWrite(ports[current_port], HIGH);
	digitalWrite(ports[current_port + 1], HIGH);
	last_light1 = current_port;
	last_light2 = current_port + 1;
	current_port += 2;
	if (current_port >= portAmount) current_port = 0;

	delay(400);
}
