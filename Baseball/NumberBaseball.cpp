#pragma once

#include "headers.h"

NumberBaseball::NumberBaseball(char permission, const std::string serverName) : _A(0), _B(0), _C(0), serverName(serverName) {//serverName (it's Prefix) 
	ch::system_clock::time_point start = ch::system_clock::now();//to measure time for generating (start)
	std::cout << serverName << " 숫자를 생성합니다" << std::endl;

	//generate three numbers randomly, different each other
	std::random_device rnDevice;
	std::mt19937 rnmt(rnDevice());
	std::uniform_int_distribution<int> dist(0, 9);

	int tried = 0;//to count for trying generate a number
	_B = dist(rnmt) + 48;//48 == char ASCII offset
	tried++;//tried
	while (_A == 0 || _B == _A) {//Is not zero(not first, not overlapped)
		_A = dist(rnmt) + 48;
		tried++;
	}
	while (_C == 0 || _A == _C || _B == _C) {//Is not zero(not first, not overlapped)
		_C = dist(rnmt) + 48;
		tried++;
	}

	ch::system_clock::time_point end = ch::system_clock::now();//to measure time for generating (end)
	ch::microseconds microSec = ch::duration_cast<ch::microseconds>(end - start);//calculate with 

	if (permission == (char)Permission::Developer) {//Developer mode, notify Answer and count tried
		std::cout << serverName << " 숫자가 생성되었습니다 : " << _A << _B << _C << " (" << microSec.count() << "us)" << " tried " << tried << " times" << std::endl;
	}
	else if (permission == (char)Permission::User) {//User mode, notify only message says completed
		std::cout << serverName << " 숫자가 생성되었습니다 (" << microSec.count() << "us 소요)" << std::endl;
	}
	/*arr[a - 49]++;
	arr[b - 49]++;
	arr[c - 49]++;
	std::cout << a << b << c << std::endl;*/ // for Debugging
}

NBResult NumberBaseball::askPlayerNumber(int& tried) {//ask player for a number
	char strike = 0, ball = 0, out = 0;//result

	//char result[4] = { 0 }; <<-- I wanted to memory result here, but I made class NumberBaseballResult
	while (1) {//infinite loop
		int timeCnt = 0;
		std::cout << serverName << ' ' << "숫자를 예측해보세요(기권하려면 000을 입력하세요) : ";
		std::cin >> _Afp >> _Bfp >> _Cfp;//scan one at a time, fp means 'from player'

		if (isAvailable(_Afp) && isAvailable(_Bfp) && isAvailable(_Cfp)) {//check if all numbers are valid
			if (_Afp != _Bfp && _Bfp != _Cfp) {//check if all numbers are different each
				if (_Afp == _A) strike++;//strikes
				else if (_Afp == _B || _Afp == _C) ball++;//balls

				if (_Bfp == _B) strike++;
				else if (_Bfp == _A || _Bfp == _C) ball++;

				if (_Cfp == _C) strike++;
				else if (_Cfp == _A || _Cfp == _B) ball++;

				else {//OUT
					out = 1;
				}
				tried++;//from main with reference &
				break;
			}

			else if ((_Afp - 48 | _Bfp - 48 | _Cfp - 48) == 0) {//are all 0? it means giving up
				std::cout << serverName << " 정답은 " << _A << _B << _C << "였습니다" << std::endl;
				return NBResult(-1, -1);//if player gave up, result is -1
			}

			else {
				std::cout << serverName << " 예측한 숫자의 각 자릿수는 모두 같지 않아야 합니다!" << std::endl;
				std::cout << serverName << " 다시 입력해주세요" << std::endl;
			}
		}
	}
	return NBResult(strike, ball);
}

inline bool NumberBaseball::isAvailable(char num) {//is num valid
	if (num > '9' || num < '0') return false;
	else return true;
}

//getters
char NumberBaseball::a() const {
	return _A;
}
char NumberBaseball::b() const {
	return _B;
}
char NumberBaseball::c() const {
	return _C;
}

std::string NumberBaseball::prefix() const {
	return serverName;
}