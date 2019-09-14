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
//	memset(res, 0, portAmount);
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

void _midSort(int *arr, int len, int *targ, int targ_len, int targ_place_index) {
	bool isOdd = len % 2;

//	//Calculate the new length
//	int newLen = isOdd ? len + 1 : len;

	// (7 - 1) / 2 = 6 / 2 = 3
	// 8 / 2 - 1 = 4 - 1 = 3
	int midleft = (isOdd ? (len - 1) / 2 : len / 2 - 1);

	// (7 - 1) / 2 = 6 / 2 = 3
	// 8 / 2 = 4
	int midright = (isOdd ? (len - 1) / 2 : len / 2);

	targ[targ_place_index] = midleft;

	targ[targ_place_index + 1] = midright;

	for (int gp = 0; gp < targ_len; gp++) {
//		printf("Port %d is %d \n", gp, ports[gp]);
		Serial.print("Port ");
		Serial.print(gp);
		Serial.print(" is ");
		Serial.println(targ[gp]);
	}

	targ_place_index += 2;

	if (len - 2 > 0) {
		int newArrLen = len - (isOdd + 1);
		int *newArr = new int[newArrLen];
		for (int ne = 0, nae = 0; ne < len; ne++) {
			if (ne != midleft and ne != midright) {
				newArr[nae++] = arr[ne];
			}
		}
		delete[] arr;
		_midSort(newArr, newArrLen, targ, targ_len, targ_place_index);
	}
}

[[deprecated]]
int *midSort(int *arr, int len) {
	bool isOdd = len % 2;

	//Calculate the new length
	int newLen = isOdd ? len + 1 : len;

	int *res = new int[newLen];

	_midSort(arr, len, res, newLen, 0);

	return res;

//	// (7 - 1) / 2 = 6 / 2 = 3
//	// 8 / 2 - 1 = 4 - 1 = 3
//	int midleft = (isOdd ? (len - 1) / 2 : len / 2 - 1);
//
//	// (7 - 1) / 2 = 6 / 2 = 3
//	// 8 / 2 = 4
//	int midright = (isOdd ? (len - 1) / 2 : len / 2);
//
//	//Initialise the result array pointer
//	int *res = new int[newLen];
//
//	for (int i = 0; i < len; i++) {
//		int element = arr[i];
//		if (i == midleft) {
//			res[0] = element;
//			continue;
//		} else if (i == midright) {
//			res[1] = element;
//			continue;
//		}
//	}
}

#endif //LIGHTBLINK_HDR_HPP
