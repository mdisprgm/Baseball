#pragma once

#ifndef __NUMBERBASEBALLRESULT_H__
#define  __NUMBERBASEBALLRESULT_H__
typedef int count_t;
typedef class NumberBaseballResult {//�����ϰ� ��Ʈ����ũ,��,�ƿ��� ����
char m_strike, m_ball, m_out;//��Ʈ����ũ,��,�ƿ�
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
} NBResult;//ª�� ���

std::ostream& operator<<(std::ostream& os, NBResult& result) {
	count_t strike = result.strike();
	count_t ball = result.ball();

	std::string strikeMsg = std::to_string(strike) + "S";
	std::string ballMsg = std::to_string(ball) + "B";

	if (strike == 0) {
		switch (ball) {
		case 1:
			os << ' ' << ballMsg << "�̶��.. �ƽ��׿�. �̹��� �ٸ� ���ڸ� �Է��غ�����!" << std::endl;
			break;
		}
	}
	return os;
}
#endif