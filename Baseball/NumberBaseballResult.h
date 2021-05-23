#pragma once

#ifndef __NUMBERBASEBALLRESULT_H__
#define  __NUMBERBASEBALLRESULT_H__
typedef int count_t;
typedef class NumberBaseballResult {//간단하게 스트라이크,볼,아웃을 저장
char m_strike, m_ball, m_out;//스트라이크,볼,아웃
public:
	NumberBaseballResult();
	NumberBaseballResult(count_t, count_t, count_t);//s,b,o

	//
	count_t strike() const;
	count_t ball() const;
	count_t out() const;

	//is out
	bool isOut();
	//is homerun
	bool isHomerun();
} NBResult;//짧게 축약

#endif