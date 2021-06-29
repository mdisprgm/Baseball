#pragma once

#include "NumberBaseballResultArray.h"
#include <cstdlib>
#include <iostream>
#include <string>

inline unsigned int isThere(char value, char* arr, int size) {
	unsigned int cnt = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) {
			++cnt;
		}
	}

	return cnt;
}

inline bool isStrike(char value, int index, char* arr, int size) {
	unsigned int cnt = isThere(value, arr, size);
	if (size == 1) {
		for (int i = 0; i < size; i++) {
			if (arr[i] == value && i == index) {
				return true;
			}
		}
	}
	else if (size != 0) {
		return false;
		std::cout << "Invalid size!! in function " << __FUNCTION__ << std::endl;
		exit(1);
	}
}

inline bool isBall(char value, int index, char* arr, int size) {
	return !isStrike(value, index, arr, size);
}