#pragma once
#include "headers.h"

#ifndef __NUMBERBASEBALL_H__
#define __NUMBERBASEBALL_H__

typedef class NumberBaseball {//안내를 위한 Server 상속
	const std::string serverName;

	char m_a = 0, m_b = 0, m_c = 0; //49 == '1', 설정된 정답
	char m_afp = 0, m_bfp = 0, m_cfp = 0; //fp == Got From Player, 플레이어가 예측한 정답

	inline bool isAvailable(char);
public:
	NumberBaseball(char, const std::string);//permission,serverName

	//getters
	char a() const;
	char b() const;
	char c() const;

	NBResult askPlayerNumber(void);
}NBBall;
#endif	