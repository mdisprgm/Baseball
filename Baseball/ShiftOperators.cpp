#include "headers.h"

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
		if ((strike ^ ball) == 0) {//both 0
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
