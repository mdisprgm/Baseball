#pragma once

#include "headers.h"

NBBall::NumberBaseball(char permission, const std::string serverName) : _A(0), _B(0), _C(0), serverName(serverName) {//Server::serverName(접두사)를 ROOT으로, 권한을 입력받음
	ch::system_clock::time_point start = ch::system_clock::now();//생성 시간 측정 (start)
	std::cout << serverName << " 숫자를 생성합니다" << std::endl;

	//랜덤한 세 자리수 생성,단 자릿수의 숫자는 모두 다름
	std::random_device rnDev;
	std::mt19937 rnmt(rnDev());
	std::uniform_int_distribution<int> dist(0, 9);

	int tried = 0;//생성을 위해 시도한 횟수
	_B = dist(rnmt) + 48;//48 == char형 오프셋
	tried++;//+1회 시도
	while (_A == 0 || _B == _A) {//0이 아니면서(처음이 아니면서 중복 X)
		_A = dist(rnmt) + 48;
		tried++;
	}
	while (_C == 0 || _A == _C || _B == _C) {//0이 아니면서(처음이 아니면서 중복 X)
		_C = dist(rnmt) + 48;
		tried++;
	}

	ch::system_clock::time_point end = ch::system_clock::now();//생성 시간 측정 (end)
	ch::microseconds microSec = ch::duration_cast<ch::microseconds>(end - start);//us 단위로 계산

	if (permission == (char)Permission::Developer) {//Developer, 개발자 모드면 정답과 시도 횟수까지 출력
		std::cout << serverName << " 숫자가 생성되었습니다 : " << _A << _B << _C << " (" << microSec.count() << "us)" << " tried " << tried << " times" << std::endl;
	}
	else if (permission == (char)Permission::User) {//USER, 유저 모드면 생성됐다는 메시지만 출력
		std::cout << serverName << " 숫자가 생성되었습니다 (" << microSec.count() << "us 소요)" << std::endl;
	}
	/*arr[a - 49]++;
	arr[b - 49]++;
	arr[c - 49]++;
	std::cout << a << b << c << std::endl;*/ // for Debugging
}

NBResult NBBall::askPlayerNumber(void) {//숫자 묻기
	char strike = 0, ball = 0, out = 0;//result
	static int triedCnt = 1;//예측한 횟수
	//char result[4] = { 0 }; <<-- 여기에 할려다가 class NumberBaseballResult 만듦
	while (1) {//무한 루프
		int timeCnt = 0;
		std::cout << serverName << ' ' << "숫자를 예측해보세요(기권하려면 000을 입력하세요) : ";
		std::cin >> _Afp >> _Bfp >> _Cfp;//하나씩 입력받고

		if (isAvailable(_Afp) && isAvailable(_Bfp) && isAvailable(_Cfp)) {//모두 유효한지 확인
			if (_Afp != _Bfp && _Bfp != _Cfp) {//중복되는지 확인
				if (_Afp == _A) strike++;//스트라이크
				else if (_Afp == _B || _Afp == _C) ball++;//볼

				if (_Bfp == _B) strike++;
				else if (_Bfp == _A || _Bfp == _C) ball++;

				if (_Cfp == _C) strike++;
				else if (_Cfp == _A || _Cfp == _B) ball++;

				else {//OUT
					out = 1;
				}
				triedCnt++;
				break;
			}

			else if ((_Afp - 48 | _Bfp - 48 | _Cfp - 48) == 0) {//모두 0인가, 그렇다면 기권
				std::cout << serverName << " 정답은 " << _A << _B << _C << "였습니다" << std::endl;
				return NBResult(-1, -1);//기권이면 Strike와 Ball을 -1로 반환
			}

			else {
				std::cout << serverName << " 예측한 숫자의 각 자릿수는 모두 같지 않아야 합니다!" << std::endl;
				std::cout << serverName << " 다시 입력해주세요" << std::endl;
			}
		}
	}
	return NBResult(strike, ball);
}

inline bool NBBall::isAvailable(char num) {//유효한 값(자릿수)인가
	if (num > '9' || num < '0') return false;
	else return true;
}

//getters
char NBBall::a() const {
	return _A;
}
char NBBall::b() const {
	return _B;
}
char NBBall::c() const {
	return _C;
}

std::string NBBall::prefix() const {
	return serverName;
}