#pragma once
#include <iostream>
#include <string>

#include "headers.h";

#include "NumberBaseballResult.h"


//constructors
NBResult::NumberBaseballResult() {//기본 생성자
	m_strike = 0;
	m_ball = 0;
	m_out = 0;
}
NBResult::NumberBaseballResult(count_t s, count_t b, count_t o) {//set 생성자 (입력받은 값으로)
	m_strike = s;
	m_ball = b;
	m_out = o;
}

//getters
count_t NBResult::strike() const {
	return m_strike;
}
count_t NBResult::ball() const {
	return m_ball;
}
count_t NBResult::out() const {
	return m_out;
}

//is out
bool NBResult::isOut() {
	if (m_strike == 0 && m_ball == 0 && m_out == 1) {
		return true;
	}
	return false;
}
//is homerun (WIN)
bool NBResult::isHomerun() {
	if (m_strike == 3 && m_ball == 0 && m_out == 0) {
		return true;
	}
	return false;
}

std::ostream& operator<<(std::ostream& os, NBResult& result) {//broadcast
	count_t strike = result.strike();
	count_t ball = result.ball();

	std::string strikeMsg = std::to_string(strike) + "S";
	std::string ballMsg = std::to_string(ball) + "B";

	if (strike == 0) {
		switch (ball) {
		case 1:
			os << ' ' << ballMsg << "이라니.. 아쉽네요. 이번엔 다른 숫자를 입력해보세요!" << std::endl;
			break;
		}
	}
	return os;
}