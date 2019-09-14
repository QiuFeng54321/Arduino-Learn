//
// Created by Qiufeng54321 on 2019-09-14.
// Copyright (C) 2019  Qiufeng54321
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#ifndef LIGHTBLINK_HDR_HPP
#define LIGHTBLINK_HDR_HPP

/*int light_change_delay = 500;

struct StateChange {
	int state;
	int changeTo;
	int delay;
};

struct LightChange : StateChange {
	LightChange(int port, int to) : StateChange() {
		state = port;
		changeTo = to;
		delay = light_change_delay;
	}
};

struct LightOn : LightChange {
	explicit LightOn(int port) : LightChange(port, HIGH) {}

	LightOn(int port, int del) : LightOn(port) {
		delay = del;
	}
};

struct LightOff : LightChange {
	explicit LightOff(int port) : LightChange(port, LOW) {}

	LightOff(int port, int del) : LightOff(port) {
		delay = del;
	}
};*/

//FLIP, MALLOC DOESN'T EXIST IN ARDUINO SDK.

/**
 * A generation function for generating ports (that might have ports that need to be excluded)
 * @param start the starting port
 * @param portAmount how many ports that need to be generated
 * @param excludes what ports should be excluded in the result
 * @param excludeAmount how many elements 'excludes' has
 * @return generated port pointer
 */
int *generatePorts(int start, int portAmount, const int *excludes = nullptr, int excludeAmount = 0) {
	int *res = new int[portAmount];
	for (int i = 0, current = start; i < portAmount;) {
		Serial.print("i and current : ");
		Serial.println(i);
		Serial.println(current);
		if (excludes != nullptr) {
			for (int e = 0; e < excludeAmount; e++) {
				if (excludes[e] == current) {
					Serial.println("Not accepted");
					current++;
					continue;
				}
			}
		}
		Serial.println("Accepted");
		res[i++] = current++;
	}
	return res;
}

#endif //LIGHTBLINK_HDR_HPP
