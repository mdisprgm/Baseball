#pragma once

#ifndef __NUMBERBASEBALLRESULT_H__
#define  __NUMBERBASEBALLRESULT_H__

typedef class NumberBaseballResult {//간단하게 스트라이크,볼,아웃을 저장
char m_strike, m_ball, m_out;//스트라이크,볼,아웃
public:
	NumberBaseballResult();
	NumberBaseballResult(char, char, char);//s,b,o

	//getters
	char strike() const;
	char ball() const;
	char out() const;

	//is out
	bool isOut();
	//is homerun
	bool isHomerun();
} NBResult;//짧게 축약
#endif