#pragma once

#include "headers.h"

NBBall::NumberBaseball(char permission, const std::string serverName) : m_a(0), m_b(0), m_c(0), serverName(serverName) {//Server::serverName(���λ�)�� ROOT����, ������ �Է¹���
	ch::system_clock::time_point start = ch::system_clock::now();//���� �ð� ���� (start)
	std::cout << serverName << " ���ڸ� �����մϴ�" << std::endl;

	//������ �� �ڸ��� ����,�� �ڸ����� ���ڴ� ��� �ٸ�
	std::random_device rnDev;
	std::mt19937 rnmt(rnDev());
	std::uniform_int_distribution<int> dist(1, 9);

	int tried = 0;//������ ���� �õ��� Ƚ��
	m_b = dist(rnmt) + 48;//48 == char�� ������
	tried++;//+1ȸ �õ�
	while (m_a == 0 || m_b == m_a) {//0�� �ƴϸ鼭(ó���� �ƴϸ鼭 �ߺ� X)
		m_a = dist(rnmt) + 48;
		tried++;
	}
	while (m_c == 0 || m_a == m_c || m_b == m_c) {//0�� �ƴϸ鼭(ó���� �ƴϸ鼭 �ߺ� X)
		m_c = dist(rnmt) + 48;
		tried++;
	}

	ch::system_clock::time_point end = ch::system_clock::now();//���� �ð� ���� (end)
	ch::microseconds microSec = ch::duration_cast<ch::microseconds>(end - start);//us ������ ���

	if (permission == (char)Permission::Developer) {//Developer, ������ ���� ����� �õ� Ƚ������ ���
		std::cout << serverName << " ���ڰ� �����Ǿ����ϴ� : " << m_a << m_b << m_c << " (" << microSec.count() << "us)" << " tried " << tried << " times" << std::endl;
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
		std::cout << serverName << ' ' << "���ڸ� �����غ����� : ";
		std::cin >> m_afp >> m_bfp >> m_cfp;//�ϳ��� �Է¹ް�

		if (isAvailable(m_afp) && isAvailable(m_bfp) && isAvailable(m_cfp)) {//��� ��ȿ���� Ȯ��
			if (m_afp != m_bfp && m_bfp != m_cfp) {//�ߺ��Ǵ��� Ȯ��
				if (m_afp == m_a) strike++;//��Ʈ����ũ
				else if (m_afp == m_b || m_afp == m_c) ball++;//��

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
				std::cout << serverName << ' ' << "������ ������ �� �ڸ����� ��� ���� �ʾƾ� �մϴ�!" << std::endl;
				std::cout << serverName << ' ' << "�ٽ� �Է����ּ���" << std::endl;
			}
		}
	}
	return NBResult(strike, ball, out);
}

inline bool NBBall::isAvailable(char num) {//��ȿ�� ��(�ڸ���)�ΰ�
	if (num > '9' || num < '0') return false;
	else return true;
}

//getters
char NBBall::a() const {
	return m_a;
}
char NBBall::b() const {
	return m_b;
}
char NBBall::c() const {
	return m_c;
}

std::string NBBall::prefix() const {
	return serverName;
}