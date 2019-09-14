#include <Arduino.h>
#include "User_Setup.h"
#include "HDR.hpp"

const int portAmount = 7, start_port = 3;

//Generate ports from 3 to 9
int *ports;

//Current port index (count from the starting port)
int current_port = start_port;

//Is it now blinking forward or backward?
//If it is blinking positive(from start_port to start_port+portAmount), it is true.
//Otherwise it is false.
bool blink_direction = true;

void setup() {
	//Initialise Serial
	Serial.begin(9600);

	ports = generatePorts(start_port, portAmount);
	//Print generated ports
	for (int gp = 0; gp < portAmount; gp++) {
//		printf("Port %d is %d \n", gp, ports[gp]);
		Serial.print("Port ");
		Serial.print(gp);
		Serial.print(" is ");
		Serial.println(ports[gp]);
	}

	//Initialise pinModes
	for (int i = 0; i < portAmount; i++) {
		pinMode(ports[i], OUTPUT);
	}
}

void loop() {
	int state_change = blink_direction ? HIGH : LOW;

	//Update the current light
	digitalWrite(current_port, state_change);

	// In/Decrease the current port
	current_port += (blink_direction ? 1 : -1);

	//Change direction if current_port reaches start_port or start_port + portAmount
	if (((current_port == start_port) and (not blink_direction)) or
		((current_port == start_port + portAmount) and blink_direction)) {
		blink_direction = !blink_direction;
	}
}
