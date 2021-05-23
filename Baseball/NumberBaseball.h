#pragma once
#include "headers.h"

#ifndef __NUMBERBASEBALL_H__
#define __NUMBERBASEBALL_H__

typedef class NumberBaseball {//�ȳ��� ���� Server ���
	const std::string serverName;

	char m_a = 0, m_b = 0, m_c = 0; //49 == '1', ������ ����
	char m_afp = 0, m_bfp = 0, m_cfp = 0; //fp == Got From Player, �÷��̾ ������ ����

	inline bool isAvailable(char);
public:
	NumberBaseball(char, const std::string);//permission,serverName

	NBResult askPlayerNumber(void);

	//getters
	char a() const;
	char b() const;
	char c() const;

	std::string prefix() const;

}NBBall;

#endif