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

#endif