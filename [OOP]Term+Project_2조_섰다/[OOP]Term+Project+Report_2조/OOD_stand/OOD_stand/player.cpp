#include "pch.h"
#include "player.h"
#include "cardDeck.h"
#include<iostream>
#include<string>

using namespace std;


player::player()
{
	money = 0; //���� ���� �ִ� �� �ʱ�ȭ
	score = 0;
}


player::~player()
{
}

//getter
int player::getPae1() {
	return pae1;
}
int player::getPae2() {
	return pae2;
}
int player::getScore() {
	return score;
}
int player::getMoney() {
	return money;
}

//setter
void player::setMoney(int m) {
	money = m;
}
void player::setPae1(int p1) {
	pae1 = p1;
}
void player::setPae2(int p2) {
	pae2 = p2;
}
void player::setScore(int s) {
	score = s;
}

// �Լ�
void player::die() {
	setPae1(-1);
	setPae2(-1);
	setScore(-1);
}

void player::print_jokbo() { //������ ����ϴ� �Լ�
	string jokbo[32] = { "����", "�Ѳ�", "�β�", "����", "�ײ�", "�ټ���", "������", "�ϰ���",
				"������", "����", "����", "���", "���", "����", "����", "�˸�",
				"�涯", "�̶�", "�ﶯ", "�綯", "����", "����", "ĥ��", "�ȶ�","����","������",
				"�嶯", "�ϻﱤ��", "���ȱ���", "������ ��ο�!","���ȱ���" }; //����
	cout << " -> " << jokbo[score] << endl;
}

void player::jokboList() {
	int a = pae1;
	int b = pae2;
	
	//1, 11: ��, ��
	//2, 12: ����, ����
	//3, 13: ��, ��
	//4, 14: ����, ����
	//5, 15: ��, ����
	//6, 16: ��, ����
	//7, 17: ������, ����
	//8, 18: ��, ��
	//9, 19: ������, ����
	//10, 20: ���罿, ����

	if ((a == 3 && b == 8) || (a == 8 && b == 3)) {
		score = 30; //���ȱ���_�ְ� ����
	}
	else if ((a == 1 && b == 8) || (a == 8 && b == 1)) { // 1��, 8��
		score = 28;   //���ȱ���
	}
	else if ((a == 1 && b == 3) || (a == 3 && b == 1)) { // 1��, 3��
		score = 27;   //�ϻﱤ��
	}
	else if (a % 10 == 0 && b % 10 == 0) { // 10��
		score = 26;   //�嶯
	}
	else if (a % 10 == 9 && b % 10 == 9) { // 9��
		score = 24;   //����
	}
	else if (a % 10 == 8 && b % 10 == 8) { // 8��
		score = 23;   //�ȶ�
	}
	else if (a % 10 == 7 && b % 10 == 7) { // 7��
		score = 22;   //ĥ��
	}
	else if (a % 10 == 6 && b % 10 == 6) { // 6��
		score = 21; //����
	}
	else if (a % 10 == 5 && b % 10 == 5) { // 5��
		score = 20; //����
	}
	else if (a % 10 == 4 && b % 10 == 4) { // 4��
		score = 19;   //�綯
	}
	else if (a % 10 == 3 && b % 10 == 3) { // 3��
		score = 18;   //�ﶯ
	}
	else if (a % 10 == 2 && b % 10 == 2) { // 2��
		score = 17;   //�̶�
	}
	else if (a % 10 == 1 && b % 10 == 1) { // 1��
		score = 16;   //�涯
	}
	else if ((a % 10 == 1 && b % 10 == 2) || (a % 10 == 2 && b % 10 == 1)) {// 1��, 2��
		score = 15;   //�˸�
	}
	else if ((a % 10 == 1 && b % 10 == 4) || (a % 10 == 4 && b % 10 == 1)) { // 1��, 4��
		score = 14;   //����
	}
	else if ((a % 10 == 1 && b % 10 == 9) || (a % 10 == 9 && b % 10 == 1)) { // 1��, 9��
		score = 13;   //����
	}
	else if ((a % 10 == 1 && b % 10 == 0) || (a % 10 == 0 && b % 10 == 1)) { // 1��, 10��
		score = 12;   //���
	}
	else if ((a % 10 == 4 && b % 10 == 10) || (a % 10 == 0 && b % 10 == 4)) { // 4��,  10��
		score = 11;   //���
	}
	else if ((a % 10 == 4 && b % 10 == 6) || (a % 10 == 6 && b % 10 == 4)) { // 4��, 6��
		score = 10;   //����
	}
	else if ((a + b) % 10 == 9) {
		score = 9;   //����
	}
	else if ((a + b) % 10 == 8) {
		score = 8;   //������
	}
	else if ((a + b) % 10 == 7) {
		score = 7;   //�ϰ���
	}
	else if ((a + b) % 10 == 6) {
		score = 6;   //������
	}
	else if ((a + b) % 10 == 5) {
		score = 5;   //�ټ���
	}
	else if ((a + b) % 10 == 4) {
		score = 4;   //�ײ�
	}
	else if ((a + b) % 10 == 3) {
		score = 3;   //����
	}
	else if ((a + b) % 10 == 2) {
		score = 2;   //�β�
	}
	else if ((a + b) % 10 == 1) {
		score = 1;   //�Ѳ�
	}
	else if ((a + b) % 10 == 0) {
		score = 0;   //����
	}
	else {
		score = 0;
	}

}


void player::getCard(cardDeck &cd) {   // ��ü�� ī�带 �̴� �Լ�
	pae1 = cd.popCard();
	pae2 = cd.popCard();

	jokboList(); //���� ���� ��� �Լ� ȣ��
}

int player::betting_type(int pp) {
	int bet, panm; // bet_����, panm_���� �ǵ�
	cout << "Betting >> 0: ���� |1: �� |2: �� |3: üũ |4: ���� |5: Ǯ" << endl;

	cout << "\n�Է�: ";
	cin >> bet;
	cout << "Player "<<pp<< " ���� : ";

	switch (bet) {
	case 0:
		cout << "�� �װڼ�!" << endl;
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
		cout << "���� ��~" << endl;

	default:
		break;
	}

	return bet;
}

 int player:: betting(int bet, vector<int>& pandon, int dMoney) {
	int temp_money = 0;

	switch (bet) {
	case 0://����: ������ �� ����. �ٸ� ��� ������ ������ ���� ��� �� ����_ ������ ����.
		this->die();
		break;
	case 1://��
		if (pandon.size() == 0) {
			this->setMoney(this->getMoney() - (dMoney / 5));
			pandon.push_back((dMoney / 5));
		}
		else {
			int temp_money = pandon[pandon.size() - 1];//�ջ���� ����
			if (temp_money > this->getMoney()) { //�ܰ��� ������ ���� ���� ���, �ܰ�ݾ׸� ���� betting
				pandon.push_back(this->getMoney());
				this->setMoney(0);
			}
			else {
				pandon.push_back(temp_money);
				this->setMoney(this->getMoney() - temp_money);
			}
		}
		break;

	case 2: //��
		if ((dMoney / 5) > this->getMoney()) {
			pandon.push_back(this->getMoney());
			this->setMoney(0);
		}
		else {
			this->setMoney(this->getMoney() - (dMoney / 5));
			pandon.push_back((dMoney / 5));
		}
		break;

	case 4://����
		temp_money = pandon[pandon.size() - 1] * 2; //�ջ���� ����*2
		if (temp_money > this->getMoney()) { //�ܰ��� ������ ���� ���� ���, �ܰ�ݾ׸� ���� betting
			pandon.push_back(this->getMoney());
			this->setMoney(0);
		}
		else {
			pandon.push_back(temp_money);
			this->setMoney(this->getMoney() - temp_money);
		}
		break;

	case 5://Ǯ: �� ����ŭ ����
		temp_money = 0;
		for (int i = 0; i < pandon.size(); i++) {
			temp_money += pandon[i];//�򸰵� ���
		}

		if (temp_money > this->getMoney()) { //�ܰ��� ������ ���� ���� ���, �ܰ�ݾ׸� ���� betting
			pandon.push_back(this->getMoney());
			this->setMoney(0);
		}
		else {
			pandon.push_back(temp_money);
			this->setMoney(this->getMoney() - temp_money);
		}
		break;

	case 3://üũ: 
	default:
		break;
	}

	int pd = 0;
	for (int i = 0; i < pandon.size(); i++) {
		pd += pandon[i];//�򸰵� ���
	}

	return pd; //���� �ǵ��� ��ȯ
}

