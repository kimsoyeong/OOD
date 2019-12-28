#pragma once
#include "cardDeck.h"

class player
{
private:
	// ��ü�� ������ ������ ȭ�� ��
	int pae1;
	int pae2;

protected:
	int score; // ��ü�� ����
	int money; // ��ü�� �ܰ�_���� �Ӵ�
	
public:
	player();

	~player();

	void die(); // ����_���� �Լ�

	int getPae1();
	int getPae2();
	int getScore();
	int getMoney();

	void setPae1(int p1);
	void setPae2(int p2);
	void setMoney(int m);
	void setScore(int s);

	void print_jokbo(); // ���� ���
	void jokboList(); // ���� ���
	void getCard(cardDeck &cd); //ī�� �޴� �Լ�
	virtual int betting_type(int pp); // ���� Ÿ��
	int betting(int bet, vector<int>& pandon, int dMoney); // ���� Ÿ�Կ� ���� ������ �����ϴ� �Լ�
};

