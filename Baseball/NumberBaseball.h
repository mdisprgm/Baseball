#pragma once

#include "NumberBaseballResult.h"

#ifndef __NUMBERBASEBALL_H__
#define __NUMBERBASEBALL_H__

typedef class NumberBaseball {//�ȳ��� ���� Server ���
	const std::string serverName;

	char _A = 0, _B = 0, _C = 0; //49 == '1', ������ ����
	char _Afp = 0, _Bfp = 0, _Cfp = 0; //fp == Got From Player, �÷��̾ ������ ����

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