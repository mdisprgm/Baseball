#pragma once

#include <iostream>
#include <string>

#include "NumberBaseballResult.h"


//constructors
NumberBaseballResult::NumberBaseballResult() {//default constructor
	_Strike = 0;
	_Ball = 0;
}
NumberBaseballResult::NumberBaseballResult(count_t s, count_t b) {//constructor to set
	_Strike = s;
	_Ball = b;
}

//getters
count_t NumberBaseballResult::strike() const {
	return _Strike;
}
count_t NumberBaseballResult::ball() const {
	return _Ball;
}

//is out
bool NumberBaseballResult::isOut() {
	if (_Strike == 0 && _Ball == 0) {
		return true;
	}
	return false;
}
//is homerun (WIN)
bool NumberBaseballResult::isHomerun() {
	if (_Strike == 3 && _Ball == 0) {
		return true;
	}
	return false;
}