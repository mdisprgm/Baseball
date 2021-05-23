﻿#include "headers.h"

enum class Permission {//권한
	Developer = 0,//개발자
	User = 1//유저
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