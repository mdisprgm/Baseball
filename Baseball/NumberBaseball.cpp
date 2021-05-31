#pragma once

#include "headers.h"

NBBall::NumberBaseball(char permission, const std::string serverName) : _A(0), _B(0), _C(0), serverName(serverName) {//Server::serverName(���λ�)�� ROOT����, ������ �Է¹���
	ch::system_clock::time_point start = ch::system_clock::now();//���� �ð� ���� (start)
	std::cout << serverName << " ���ڸ� �����մϴ�" << std::endl;

	//������ �� �ڸ��� ����,�� �ڸ����� ���ڴ� ��� �ٸ�
	std::random_device rnDev;
	std::mt19937 rnmt(rnDev());
	std::uniform_int_distribution<int> dist(0, 9);

	int tried = 0;//������ ���� �õ��� Ƚ��
	_B = dist(rnmt) + 48;//48 == char�� ������
	tried++;//+1ȸ �õ�
	while (_A == 0 || _B == _A) {//0�� �ƴϸ鼭(ó���� �ƴϸ鼭 �ߺ� X)
		_A = dist(rnmt) + 48;
		tried++;
	}
	while (_C == 0 || _A == _C || _B == _C) {//0�� �ƴϸ鼭(ó���� �ƴϸ鼭 �ߺ� X)
		_C = dist(rnmt) + 48;
		tried++;
	}

	ch::system_clock::time_point end = ch::system_clock::now();//���� �ð� ���� (end)
	ch::microseconds microSec = ch::duration_cast<ch::microseconds>(end - start);//us ������ ���

	if (permission == (char)Permission::Developer) {//Developer, ������ ���� ����� �õ� Ƚ������ ���
		std::cout << serverName << " ���ڰ� �����Ǿ����ϴ� : " << _A << _B << _C << " (" << microSec.count() << "us)" << " tried " << tried << " times" << std::endl;
	}
	else if (permission == (char)Permission::User) {//USER, ���� ���� �����ƴٴ� �޽����� ���
		std::cout << serverName << " ���ڰ� �����Ǿ����ϴ� (" << microSec.count() << "us �ҿ�)" << std::endl;
	}
	/*arr[a - 49]++;
	arr[b - 49]++;
	arr[c - 49]++;
	std::cout << a << b << c << std::endl;*/ // for Debugging
}

NBResult NBBall::askPlayerNumber(void) {//���� ����
	char strike = 0, ball = 0, out = 0;//result
	static int triedCnt = 1;//������ Ƚ��
	//char result[4] = { 0 }; <<-- ���⿡ �ҷ��ٰ� class NumberBaseballResult ����
	while (1) {//���� ����
		int timeCnt = 0;
		std::cout << serverName << ' ' << "���ڸ� �����غ�����(����Ϸ��� 000�� �Է��ϼ���) : ";
		std::cin >> _Afp >> _Bfp >> _Cfp;//�ϳ��� �Է¹ް�

		if (isAvailable(_Afp) && isAvailable(_Bfp) && isAvailable(_Cfp)) {//��� ��ȿ���� Ȯ��
			if (_Afp != _Bfp && _Bfp != _Cfp) {//�ߺ��Ǵ��� Ȯ��
				if (_Afp == _A) strike++;//��Ʈ����ũ
				else if (_Afp == _B || _Afp == _C) ball++;//��

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

			else if ((_Afp - 48 | _Bfp - 48 | _Cfp - 48) == 0) {//��� 0�ΰ�, �׷��ٸ� ���
				std::cout << serverName << " ������ " << _A << _B << _C << "�����ϴ�" << std::endl;
				return NBResult(-1, -1);//����̸� Strike�� Ball�� -1�� ��ȯ
			}

			else {
				std::cout << serverName << " ������ ������ �� �ڸ����� ��� ���� �ʾƾ� �մϴ�!" << std::endl;
				std::cout << serverName << " �ٽ� �Է����ּ���" << std::endl;
			}
		}
	}
	return NBResult(strike, ball);
}

inline bool NBBall::isAvailable(char num) {//��ȿ�� ��(�ڸ���)�ΰ�
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