#pragma once

#ifndef __NUMBERBASEBALLRESULT_H__
#define  __NUMBERBASEBALLRESULT_H__
typedef unsigned int count_t;
typedef class NumberBaseballResult {//strike,ball
count_t _Strike = 0, _Ball = 0;//strike,ball
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
};//shorten
typedef NumberBaseballResult NBResult;
#endif