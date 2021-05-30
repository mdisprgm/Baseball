#pragma once
#include <iostream>
#include <string>

#include "headers.h"

#include "NumberBaseballResult.h"

//constructors
NBResult::NumberBaseballResult() {//�⺻ ������
	m_strike = 0;
	m_ball = 0;
}
NBResult::NumberBaseballResult(count_t s, count_t b, count_t o) {//set ������ (�Է¹��� ������)
	m_strike = s;
	m_ball = b;
}

//getters
count_t NBResult::strike() const {
	return m_strike;
}
count_t NBResult::ball() const {
	return m_ball;
}

//is out
bool NBResult::isOut() {
	if (m_strike == 0 && m_ball == 0) {
		return true;
	}
	return false;
}
//is homerun (WIN)
bool NBResult::isHomerun() {
	if (m_strike == 3 && m_ball == 0) {
		return true;
	}
	return false;
}