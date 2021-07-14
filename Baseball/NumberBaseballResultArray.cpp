#pragma once

#include "NumberBaseballResultArray.h"

#include <cstdlib>//exit
#include <iostream>
#include <string>

inline unsigned int isThere(char value, char* arr, int size) {
	if (size < 1) {
		std::cerr << "Invalid size!! in function" << __FUNCTION__ << std::endl;
		exit(1);
	}
	unsigned int cnt = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] == value) {
			++cnt;
		}
	}
	return cnt;
}

inline bool isStrike(char value, int index, char* arr, int size) {
	unsigned int cnt = isThere(value, arr, size);//get count of the number
	if (cnt == 1) {
		if (arr[index] == value) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		std::cerr << "count is not 1" << std::endl;
		exit(1);
	}
	return false;
}

inline bool isBall(char value, int index, char* arr, int size) {
	unsigned int cnt = isThere(value, arr, size);
	if (cnt == 1) {
		if (arr[index] != value) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		std::cerr << "count is not 1" << std::endl;
		exit(1);
	}
	return false;
}