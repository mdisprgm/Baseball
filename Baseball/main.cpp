#include <iostream>
#include <chrono>
#include <random>
#include <conio.h>

#include "headers.h"

#include "broadcast.h"

std::ostream& operator<<(std::ostream& os, NBBall& game) {
	os << game.prefix() << ' ';
	return os;
}
std::ostream& operator<<(std::ostream& os, NBResult& result) {
	count_t strike = result.strike();
	count_t ball = result.ball();

	std::string strikeMsg = std::to_string(strike) + "S";
	std::string ballMsg = std::to_string(ball) + "B";

	if (strike == 0) {
		switch (ball) {
		case 1:
			os << ballMsg << "이라니.. 아쉽네요. 이번엔 다른 숫자를 입력해보세요!";
			break;
		}
	}
	return os;
}

int main() {
	NBBall game(0,"[GAME]");
	NBResult result(0,1,0);
	std::cout << game << result << "HI" << std::endl;
	return 0;
}