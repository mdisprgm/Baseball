#include "NumberBaseballResult.h"
#pragma once


//constructors
NBResult::NumberBaseballResult() {//기본 생성자
	m_strike = 0;
	m_ball = 0;
	m_out = 0;
}
NBResult::NumberBaseballResult(char s, char b, char o) {//set 생성자 (입력받은 값으로)
	m_strike = s;
	m_ball = b;
	m_out = o;
}

//getters
char NBResult::strike() const {
	return m_strike;
}
char NBResult::ball() const {
	return m_ball;
}
char NBResult::out() const {
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