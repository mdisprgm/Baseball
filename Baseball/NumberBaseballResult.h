#pragma once
typedef class NumberBaseballResult {//�����ϰ� ��Ʈ����ũ,��,�ƿ��� ����
char m_strike, m_ball, m_out;//��Ʈ����ũ,��,�ƿ�
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
} NBResult;//ª�� ���

