#pragma once
#include "cardDeck.h"

class player
{
private:
	// 객체가 가지는 두장의 화투 패
	int pae1;
	int pae2;

protected:
	int score; // 객체의 점수
	int money; // 객체의 잔고_게임 머니
	
public:
	player();

	~player();

	void die(); // 베팅_다이 함수

	int getPae1();
	int getPae2();
	int getScore();
	int getMoney();

	void setPae1(int p1);
	void setPae2(int p2);
	void setMoney(int m);
	void setScore(int s);

	void print_jokbo(); // 족보 출력
	void jokboList(); // 족보 계산
	void getCard(cardDeck &cd); //카드 받는 함수
	virtual int betting_type(int pp); // 베팅 타입
	int betting(int bet, vector<int>& pandon, int dMoney); // 베팅 타입에 따라 베팅을 진행하는 함수
};

