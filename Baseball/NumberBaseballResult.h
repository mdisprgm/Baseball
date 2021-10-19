#pragma once

#ifndef __NUMBERBASEBALLRESULT_H__
#define  __NUMBERBASEBALLRESULT_H__
typedef int count_t;
typedef class NumberBaseballResult {//strike,ball
char _Strike, _Ball;//strike,ball
public:
	NumberBaseballResult();
	NumberBaseballResult(count_t, count_t);//s,b,o

	//
	count_t strike() const;
	count_t ball() const;

	//is out
	bool isOut();
	//is homerun
	bool isHomerun();
} NBResult;//shorten

#endif