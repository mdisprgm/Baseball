#pragma once
#include "headers.h"

#ifndef __NUMBERBASEBALL_H__
#define __NUMBERBASEBALL_H__

typedef class NumberBaseball {//안내를 위한 Server 상속
	const std::string serverName;

	char m_a, m_b, m_c; //49 == '1', 설정된 정답
	char m_afp, m_bfp, m_cfp; //fp == Got From Player, 플레이어가 예측한 정답

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