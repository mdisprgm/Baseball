#pragma once
#include "headers.h"

#ifndef __NUMBERBASEBALL_H__
#define __NUMBERBASEBALL_H__

typedef class NumberBaseball {//�ȳ��� ���� Server ���
	const std::string serverName;

	char m_a, m_b, m_c; //49 == '1', ������ ����
	char m_afp, m_bfp, m_cfp; //fp == Got From Player, �÷��̾ ������ ����

	inline bool isAvailable(char);
public:
	NumberBaseball(char, const std::string);//permission,serverName

	NBResult askPlayerNumber();

	//getters
	char a() const;
	char b() const;
	char c() const;
}NBBall;
#endif