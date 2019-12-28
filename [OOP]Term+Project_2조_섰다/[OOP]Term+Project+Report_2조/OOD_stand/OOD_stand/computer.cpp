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

int computer::betting_type(int pp) { //pp는 플레이어가 몇 번째 플레이어인지를 말함
	srand(static_cast<unsigned int>(time(0))); // 초기 시드 값을 시스템 클럭으로 설정

	int k;

	// computer는 자신의 족보 점수에 따라 다르게 베팅을 수행할 수 있다.
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

	cout << "Player"<< pp <<" 베팅 : ";

	int time = (rand() % 10) * 1000;
	Sleep(time); //시간 랜덤 대기

	switch (bet) {
	case 0:
		cout << "다이" << endl;
		break;
	case 1:
		cout << "콜" << endl;
		break;
	case 2:
		cout << "삥" << endl;
		break;
	case 3:
		cout << "체크" << endl;
		break;

	case 4:
		cout << "묻고 따블로 가!" << endl;
		break;

	case 5:
		cout << "풀" << endl;

	default:
		break;
	}

	return bet;
}
