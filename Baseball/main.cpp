#include <iostream>

#include <cstdlib> //system()
#include <chrono> //time
#include <random> //random
#include <conio.h>//_getch()

#include "headers.h"

int main() {
	while (1) {
		system("cls");//clear on launch

		const std::string serverName = "[GAME]";
		std::cout <<serverName << "\t\b0 : 개발자 테스트 모드\n\t\b1 : 유저 플레이 모드\n" << serverName << ' ' << "모드를 선택하세요 : ";

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

			std::string strikeMsg;//스트라이크 수
			std::string ballMsg;//볼 수

			if (result.isHomerun()) {//정답이면
				char ifRestart = 0;
				std::cout << "대단해요! 정답은 " << game.a() << game.b() << game.c() << "입니다." << std::endl;

				std::cout << "게임을 다시 시작하시겠습니까? (Y/N) : ";
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
			else {
				std::cout << game << result << std::endl;
			}
		}
	}
}