#pragma once
#ifndef __HEADERS_H__
#define __HEADERS_H__

#include <iostream>
#include <string>
#include <random>

#include <chrono>
namespace ch = std::chrono;


#include <conio.h>

#include "NumberBaseballResult.h"
#include "NumberBaseball.h"

//Permissions
enum class Permission {//권한
	Developer = 0,//개발자
	User = 1//유저
};

#endif