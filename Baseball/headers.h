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
enum class Permission : char {//Permission
	Developer = '0',//for Developer
	User = '1'//for common User
};

#endif