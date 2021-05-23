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

std::ostream& operator<<(std::ostream& os, NBResult& result) {
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
#endif