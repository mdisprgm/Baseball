#include <iostream>
#include <string>
#include <random>
#include <chrono>

#include <conio.h>;

#include "headers.h"

namespace ch = std::chrono;

enum Permission {//권한
	Developer = 0,//개발자
	User = 1//유저
};



class NumberBaseball {//안내를 위한 Server 상속
	const std::string serverName;

	char m_a, m_b, m_c; //49 == '1', 설정된 정답
	char m_afp, m_bfp, m_cfp; //fp == Got From Player, 플레이어가 예측한 정답

	inline bool isAvailable(char num) {//유효한 값(자릿수)인가
		if (num > '9' || num < '0') return false;
		else return true;
	}
public:
	NumberBaseball(char permission, const std::string serverName) : m_a(0), m_b(0), m_c(0), serverName(serverName) {//Server::serverName(접두사)를 ROOT으로, 권한을 입력받음
		ch::system_clock::time_point start = ch::system_clock::now();//생성 시간 측정 (start)
		std::cout << serverName << "숫자를 생성합니다" << std::endl;

		//랜덤한 세 자리수 생성,단 자릿수의 숫자는 모두 다름
		std::random_device rnDev;
		std::mt19937 rnmt(rnDev());
		std::uniform_int_distribution<int> dist(1, 9);

		int tried = 0;//생성을 위해 시도한 횟수
		m_b = dist(rnmt) + 48;//48 == char형 오프셋
		tried++;//+1회 시도
		while (m_a == 0 || m_b == m_a) {//0이 아니면서(처음이 아니면서 중복 X)
			m_a = dist(rnmt) + 48;
			tried++;
		}
		while (m_c == 0 || m_a == m_c || m_b == m_c) {//0이 아니면서(처음이 아니면서 중복 X)
			m_c = dist(rnmt) + 48;
			tried++;
		}

		ch::system_clock::time_point end = ch::system_clock::now();//생성 시간 측정 (end)
		ch::microseconds microSec = ch::duration_cast<ch::microseconds>(end - start);//us 단위로 계산

		if (permission == Developer) {//Developer, 개발자 모드면 정답과 시도 횟수까지 출력
			std::cout << serverName << " 숫자가 생성되었습니다 : " << m_a << m_b << m_c << " (" << microSec.count() << "us)" << " tried " << tried << " times" << std::endl;
		}
		else if (permission == User) {//USER, 유저 모드면 생성됐다는 메시지만 출력
			std::cout << serverName << " 숫자가 생성되었습니다 (" << microSec.count() << "us 소요)" << std::endl;
		}
		/*arr[a - 49]++;
		arr[b - 49]++;
		arr[c - 49]++;
		std::cout << a << b << c << std::endl;*/ // for Debugging
	}

	NBResult askPlayerNumber() {//숫자 묻기
		char strike = 0, ball = 0, out = 0;//result

		static int triedCnt = 1;//예측한 횟수
		//char result[4] = { 0 }; <<-- 여기에 할려다가 class NumberBaseballResult 만듦
		while (1) {//무한 루프
			std::cout << serverName << ' ' << "숫자를 예측해보세요 : ";
			std::cin >> m_afp >> m_bfp >> m_cfp;//하나씩 입력받고

			if (isAvailable(m_afp) && isAvailable(m_bfp) && isAvailable(m_cfp)) {//모두 유효한지 확인
				if (m_afp != m_bfp && m_bfp != m_cfp) {//중복되는지 확인
					if (m_afp == m_a) strike++;//스트라이크
					else if (m_afp == m_b || m_afp == m_c) ball++;//볼

					if (m_bfp == m_b) strike++;
					else if (m_bfp == m_a || m_bfp == m_c) ball++;

					if (m_cfp == m_c) strike++;
					else if (m_cfp == m_a || m_cfp == m_b) ball++;

					else {//OUT
						out = 1;
					}
					triedCnt++;
					break;
				}
				else {
					std::cout << serverName << ' ' << "예측한 숫자의 각 자릿수는 모두 같지 않아야 합니다!" << std::endl;
					std::cout << serverName << ' ' << "다시 입력해주세요" << std::endl;
				}
			}
		}
		return NBResult(strike, ball, out);
	}
	//getters
	char a() const {
		return m_a;
	}
	char b() const {
		return m_b;
	}
	char c() const {
		return m_c;
	}
};



int main() {
	while (1) {
		const std::string serverName = "[GAME]";

		char permission;
		std::cout << "0 : 개발자 테스트 모드\n1 : 유저 플레이 모드\n" << serverName << ' ' << "모드를 선택하세요 : ";
		std::cin >> permission;

		if (permission > '9' || permission < '0') {
			std::cout << serverName << ' ' << "유효하지 않은 숫자입니다" << std::endl;
			return 0;
		}
		else if (permission != '0' && permission != '1') {
			std::cout << serverName << ' ' << "허용되지 않는 모드입니다" << std::endl;
		}

		NumberBaseball game(permission - 48, serverName); //auto generate a number
									//'0' to 0

		while (1) {//GAME START!
			NBResult result = game.askPlayerNumber();

			std::string strikeMsg;//스트라이크 수
			std::string ballMsg;//볼 수

			if (result.isOut()) {//아웃이면
				std::cout << "아웃입니다! 입력한 숫자와 정답이 전혀 일치하지 않습니다" << std::endl;
			}
			else if (result.isHomerun()) {//정답이면
				std::cout << "대단해요! 정답은 " << game.a() << game.b() << game.c() << "입니다." << std::endl;
				std::cout << "게임을 다시 시작하시겠습니까? (Y/N) : ";
				char restart = _getch();
				std::cout << std::endl;
				if (restart == 'N' || restart == 'n') {
					return 0; //return in main; exit
				}
				else if (restart == 'Y' || restart == 'y') {
					break; break;
				}

			}
			else {
				int strikes = result.strike();
				int balls = result.ball();

				strikeMsg = std::to_string(strikes) + "S";
				ballMsg = std::to_string(balls) + "B";

				if (strikes == 0) {
					switch (balls) {
					case 1:
						std::cout << serverName << ' ' << ballMsg << "이라니.. 아쉽네요. 이번엔 다른 숫자를 입력해보세요!" << std::endl;
						break;
					case 2:
						std::cout << serverName << ' ' << ballMsg << "..! 꽤 좋아요, 다른 숫자도 입력해보세요" << std::endl;
						break;
					case 3:
						std::cout << serverName << ' ' << ballMsg << "!! 정답에 거의 근접해요" << std::endl;
						break;
					}
				}
				if (strikes == 1) {
					switch (balls) {
					case 0:
						std::cout << serverName << ' ' << strikeMsg << "! 과연 무엇이 옳은 숫자일까요?" << std::endl;
						break;
					case 1:
						std::cout << serverName << ' ' << strikeMsg << ' ' << ballMsg << " 좋아요. 빨리 다른 숫자도 맞춰보는 거에요!" << std::endl;
						break;
					case 2:
						std::cout << serverName << ' ' << strikeMsg << ' ' << ballMsg << "! 정답은 이 숫자들로만 이루어져있겠군요!" << std::endl;
						break;
					}
				}
				if (strikes == 2) {
					switch (balls) {
					case 0:
						std::cout << serverName << ' ' << strikeMsg << "! 이제 하나만 맞추면 되는데.." << std::endl;
						break;
					}
				}
			}
		}
	}
	return 0;
}