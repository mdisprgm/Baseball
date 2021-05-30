#pragma once
#include <iostream>
#include <string>

#include "headers.h"

#include "NumberBaseballResult.h"

//constructors
NBResult::NumberBaseballResult() {//기본 생성자
	_Strike = 0;
	_Ball = 0;
}
NBResult::NumberBaseballResult(count_t s, count_t b) {//set 생성자 (입력받은 값으로)
	_Strike = s;
	_Ball = b;
}

//getters
count_t NBResult::strike() const {
	return _Strike;
}
count_t NBResult::ball() const {
	return _Ball;
}

//is out
bool NBResult::isOut() {
	if (_Strike == 0 && _Ball == 0) {
		return true;
	}
	return false;
}
//is homerun (WIN)
bool NBResult::isHomerun() {
	if (_Strike == 3 && _Ball == 0) {
		return true;
	}
	return false;
}