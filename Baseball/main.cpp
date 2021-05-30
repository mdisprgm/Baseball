#include <iostream>

#include <cstdlib> //system()
#include <chrono> //time
#include <random> //random
#include <conio.h>//_getch()

#include "headers.h"

#include "broadcast.h"


//NBBall
std::ostream& operator<<(std::ostream& os, NBBall& game) {
	os << game.prefix() << ' ';
	return os;
}

//NBResult
std::ostream& operator<<(std::ostream& os, NBResult& result) {
	const count_t strike = result.strike();
	const count_t ball = result.ball();

	std::string strikeMsg = std::to_string(strike) + "S";
	std::string ballMsg = std::to_string(ball) + "B";

	if (strike != 3) {
		if ((strike | ball) == 0) {//both 0
			os << BC::messages[strike][ball];
		}
		else {
			os << strikeMsg << ' ' << ballMsg << BC::messages[strike][ball];//일단 출력
		}
	}

	if (strike == 2 && ball != 0) {
		exit(strike * 10 + ball);
	}
	else if (strike == 1 && ball == 3) {
		exit(strike * 10 + ball);
	}

	return os;
}


int main() {
	while (1) {
		system("cls");//clear on launch

		const std::string serverName = "[GAME]";
		std::cout << serverName << "\t\b0 : 개발자 테스트 모드\n\t\b1 : 유저 플레이 모드\n" << serverName << ' ' << "모드를 선택하세요 : ";

		char permission = 0;
		std::cin >> permission;

		while (permission != (char)Permission::Developer && permission != (char)Permission::User) {
			if (permission > '9' || permission < '0') {
				std::cout << serverName << ' ' << "유효하지 않은 숫자입니다" << std::endl;
				return 0;
			}
			else {//permission
				std::cout << serverName << ' ' << "허용되지 않는 모드입니다" << std::endl;
				return 0;
			}
		}

		NBBall game = NBBall(permission, serverName); //auto generate a number in Constructor

		while (1) {//GAME START!
			NBResult result = game.askPlayerNumber();

			if (result.isHomerun()) {//정답이면
				std::cout << "대단해요! 정답은 " << game.a() << game.b() << game.c() << "입니다." << std::endl;
			}
			if ((result.strike() == -1 && result.ball() == -1) || result.isHomerun()) {
				std::cout << "게임을 다시 시작하시겠습니까? (Y/N) : ";
				char ifRestart = 0;
				while (ifRestart == 0) {
					ifRestart = _getch();
					if (ifRestart == 'N' || ifRestart == 'n') {
						return 0; //return in main; exit
					}
					else if (ifRestart == 'Y' || ifRestart == 'y') {
						break;
					}
					else {
						ifRestart = 0;
					}
				};
				system("cls");
				break;
			}
			std::cout << game << result << std::endl;
		}
	}
}