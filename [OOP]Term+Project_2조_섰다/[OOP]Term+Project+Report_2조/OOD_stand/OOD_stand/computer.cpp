#include "pch.h"
#include "player.h"
#include "computer.h"
#include<random>
#include <Windows.h>
#include <ctime>
#include <cstdlib>
#include<iostream>
#include<string>

using namespace std;

computer::computer()
{
}


computer::~computer()
{
}

int computer::betting_type(int pp) { //pp�� �÷��̾ �� ��° �÷��̾������� ����
	srand(static_cast<unsigned int>(time(0))); // �ʱ� �õ� ���� �ý��� Ŭ������ ����

	int k;

	// computer�� �ڽ��� ���� ������ ���� �ٸ��� ������ ������ �� �ִ�.
	if (score < 12) {
		k = 4;
	}
	else if (score < 16) {
		k = 5;
	}
	else if (score < 27) {
		k = 6;
	}
	else {
		k = 5;
	}
	int bet = rand() % k;
	if (score > 26) {
		bet += 1;
	}

	cout << "Player"<< pp <<" ���� : ";

	int time = (rand() % 10) * 1000;
	Sleep(time); //�ð� ���� ���

	switch (bet) {
	case 0:
		cout << "����" << endl;
		break;
	case 1:
		cout << "��" << endl;
		break;
	case 2:
		cout << "��" << endl;
		break;
	case 3:
		cout << "üũ" << endl;
		break;

	case 4:
		cout << "���� ����� ��!" << endl;
		break;

	case 5:
		cout << "Ǯ" << endl;

	default:
		break;
	}

	return bet;
}
