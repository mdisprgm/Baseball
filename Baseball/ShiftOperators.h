#pragma once

#ifndef __SHIFTOPERATROS_H__
#define __SHIFTOPERATORS_H__

#include <iostream>

#include "NumberBaseball.h"
#include "NumberBaseballResult.h"

//NBBall (Prefix)
std::ostream& operator<<(std::ostream& , NBBall&);

//NBResult
std::ostream& operator<<(std::ostream& , NBResult&);
#endif