#pragma once

#include "NumberBaseballResult.h"

#ifndef __NUMBERBASEBALL_H__
#define __NUMBERBASEBALL_H__

typedef class NumberBaseball {
	const std::string serverName;

	char _A = 0, _B = 0, _C = 0; //49 == '1', real answer
	char _Afp = 0, _Bfp = 0, _Cfp = 0; //fp == Got From Player, answer player guessed

	inline bool isAvailable(char);
public:
	NumberBaseball(char, const std::string);//permission,serverName

	NBResult askPlayerNumber();

	//getters
	char a() const;
	char b() const;
	char c() const;

	std::string prefix() const;

} NBBall;

#endif