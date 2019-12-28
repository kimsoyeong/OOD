#include "pch.h"
#include "player.h"
#include "cardDeck.h"
#include<iostream>
#include<string>

using namespace std;


player::player()
{
	money = 0; //³»°¡ °®°í ÀÖ´Â µ· ÃÊ±âÈ­
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

// ÇÔ¼ö
void player::die() {
	setPae1(-1);
	setPae2(-1);
	setScore(-1);
}

void player::print_jokbo() { //Á·º¸¸¦ Ãâ·ÂÇÏ´Â ÇÔ¼ö
	string jokbo[32] = { "¸ÁÅë", "ÇÑ²ý", "µÎ²ý", "¼¼²ý", "³×²ý", "´Ù¼¸²ý", "¿©¼¸²ý", "ÀÏ°ö²ý",
				"¿©´ü²ý", "°©¿À", "¼¼·ú", "Àå»ç", "Àå»æ", "±¸»æ", "µ¶»ç", "¾Ë¸®",
				"»æ¶¯", "ÀÌ¶¯", "»ï¶¯", "»ç¶¯", "¿À¶¯", "À°¶¯", "Ä¥¶¯", "ÆÈ¶¯","±¸¶¯","¶¯ÀâÀÌ",
				"Àå¶¯", "ÀÏ»ï±¤¶¯", "ÀÏÆÈ±¤¶¯", "¾ÏÇà¾î»ç ÃâµÎ¿ä!","»ïÆÈ±¤¶¯" }; //Á·º¸
	cout << " -> " << jokbo[score] << endl;
}

void player::jokboList() {
	int a = pae1;
	int b = pae2;
	
	//1, 11: ±¤, ²ý
	//2, 12: ²ý»õ, ²ý´Ü
	//3, 13: ±¤, ²ý
	//4, 14: ²ý»õ, ²ý´Ü
	//5, 15: ²ý, ²ý´Ü
	//6, 16: ²ý, ²ý´Ü
	//7, 17: ²ýµÅÁö, ²ý´Ü
	//8, 18: ±¤, ²ý
	//9, 19: ²ý»¡°­, ²ý´Ü
	//10, 20: ²ý»ç½¿, ²ý´Ü

	if ((a == 3 && b == 8) || (a == 8 && b == 3)) {
		score = 30; //»ïÆÈ±¤¶¯_ÃÖ°í Á·º¸
	}
	else if ((a == 1 && b == 8) || (a == 8 && b == 1)) { // 1±¤, 8±¤
		score = 28;   //ÀÏÆÈ±¤¶¯
	}
	else if ((a == 1 && b == 3) || (a == 3 && b == 1)) { // 1±¤, 3±¤
		score = 27;   //ÀÏ»ï±¤¶¯
	}
	else if (a % 10 == 0 && b % 10 == 0) { // 10¿ù
		score = 26;   //Àå¶¯
	}
	else if (a % 10 == 9 && b % 10 == 9) { // 9¿ù
		score = 24;   //±¸¶¯
	}
	else if (a % 10 == 8 && b % 10 == 8) { // 8¿ù
		score = 23;   //ÆÈ¶¯
	}
	else if (a % 10 == 7 && b % 10 == 7) { // 7¿ù
		score = 22;   //Ä¥¶¯
	}
	else if (a % 10 == 6 && b % 10 == 6) { // 6¿ù
		score = 21; //À°¶¯
	}
	else if (a % 10 == 5 && b % 10 == 5) { // 5¿ù
		score = 20; //¿À¶¯
	}
	else if (a % 10 == 4 && b % 10 == 4) { // 4¿ù
		score = 19;   //»ç¶¯
	}
	else if (a % 10 == 3 && b % 10 == 3) { // 3¿ù
		score = 18;   //»ï¶¯
	}
	else if (a % 10 == 2 && b % 10 == 2) { // 2¿ù
		score = 17;   //ÀÌ¶¯
	}
	else if (a % 10 == 1 && b % 10 == 1) { // 1¿ù
		score = 16;   //»æ¶¯
	}
	else if ((a % 10 == 1 && b % 10 == 2) || (a % 10 == 2 && b % 10 == 1)) {// 1¿ù, 2¿ù
		score = 15;   //¾Ë¸®
	}
	else if ((a % 10 == 1 && b % 10 == 4) || (a % 10 == 4 && b % 10 == 1)) { // 1¿ù, 4¿ù
		score = 14;   //µ¶»ç
	}
	else if ((a % 10 == 1 && b % 10 == 9) || (a % 10 == 9 && b % 10 == 1)) { // 1¿ù, 9¿ù
		score = 13;   //±¸»æ
	}
	else if ((a % 10 == 1 && b % 10 == 0) || (a % 10 == 0 && b % 10 == 1)) { // 1¿ù, 10¿ù
		score = 12;   //Àå»æ
	}
	else if ((a % 10 == 4 && b % 10 == 10) || (a % 10 == 0 && b % 10 == 4)) { // 4¿ù,  10¿ù
		score = 11;   //Àå»ç
	}
	else if ((a % 10 == 4 && b % 10 == 6) || (a % 10 == 6 && b % 10 == 4)) { // 4¿ù, 6¿ù
		score = 10;   //¼¼·ú
	}
	else if ((a + b) % 10 == 9) {
		score = 9;   //°©¿À
	}
	else if ((a + b) % 10 == 8) {
		score = 8;   //¿©´ü²ý
	}
	else if ((a + b) % 10 == 7) {
		score = 7;   //ÀÏ°ö²ý
	}
	else if ((a + b) % 10 == 6) {
		score = 6;   //¿©¼¸²ý
	}
	else if ((a + b) % 10 == 5) {
		score = 5;   //´Ù¼¸²ý
	}
	else if ((a + b) % 10 == 4) {
		score = 4;   //³×²ý
	}
	else if ((a + b) % 10 == 3) {
		score = 3;   //¼¼²ý
	}
	else if ((a + b) % 10 == 2) {
		score = 2;   //µÎ²ý
	}
	else if ((a + b) % 10 == 1) {
		score = 1;   //ÇÑ²ý
	}
	else if ((a + b) % 10 == 0) {
		score = 0;   //¸ÁÅë
	}
	else {
		score = 0;
	}

}


void player::getCard(cardDeck &cd) {   // °´Ã¼°¡ Ä«µå¸¦ »Ì´Â ÇÔ¼ö
	pae1 = cd.popCard();
	pae2 = cd.popCard();

	jokboList(); //Á·º¸ Á¡¼ö °è»ê ÇÔ¼ö È£Ãâ
}

int player::betting_type(int pp) {
	int bet, panm; // bet_º£ÆÃ, panm_ÇöÀç ÆÇµ·
	cout << "Betting >> 0: ´ÙÀÌ |1: ÄÝ |2: »æ |3: Ã¼Å© |4: µû´ç |5: Ç®" << endl;

	cout << "\nÀÔ·Â: ";
	cin >> bet;
	cout << "Player "<<pp<< " º£ÆÃ : ";

	switch (bet) {
	case 0:
		cout << "³­ Á×°Ú¼Ò!" << endl;
		break;
	case 1:
		cout << "ÄÝ" << endl;
		break;
	case 2:
		cout << "»æ" << endl;
		break;
	case 3:
		cout << "Ã¼Å©" << endl;
		break;

	case 4:
		cout << "¹¯°í µûºí·Î °¡!" << endl;
		break;

	case 5:
		cout << "ÅÁÁø Àë~" << endl;

	default:
		break;
	}

	return bet;
}

 int player:: betting(int bet, vector<int>& pandon, int dMoney) {
	int temp_money = 0;

	switch (bet) {
	case 0://´ÙÀÌ: º£ÆÃÇÑ µ· ÀÒÀ½. ´Ù¸¥ »ç¶÷ °ÔÀÓÀÌ ³¡³¯¶§ ±îÁö ´ë±â ÈÄ Á¾·á_ ¹«Á¶°Ç Áø´Ù.
		this->die();
		break;
	case 1://ÄÝ
		if (pandon.size() == 0) {
			this->setMoney(this->getMoney() - (dMoney / 5));
			pandon.push_back((dMoney / 5));
		}
		else {
			int temp_money = pandon[pandon.size() - 1];//¾Õ»ç¶÷ÀÌ ³½µ·
			if (temp_money > this->getMoney()) { //ÀÜ°íº¸´Ù ³»·Á´Â µ·ÀÌ ¸¹Àº °æ¿ì, ÀÜ°í±Ý¾×¸¸ ÀüºÎ betting
				pandon.push_back(this->getMoney());
				this->setMoney(0);
			}
			else {
				pandon.push_back(temp_money);
				this->setMoney(this->getMoney() - temp_money);
			}
		}
		break;

	case 2: //»æ
		if ((dMoney / 5) > this->getMoney()) {
			pandon.push_back(this->getMoney());
			this->setMoney(0);
		}
		else {
			this->setMoney(this->getMoney() - (dMoney / 5));
			pandon.push_back((dMoney / 5));
		}
		break;

	case 4://µû´ç
		temp_money = pandon[pandon.size() - 1] * 2; //¾Õ»ç¶÷ÀÌ ³½µ·*2
		if (temp_money > this->getMoney()) { //ÀÜ°íº¸´Ù ³»·Á´Â µ·ÀÌ ¸¹Àº °æ¿ì, ÀÜ°í±Ý¾×¸¸ ÀüºÎ betting
			pandon.push_back(this->getMoney());
			this->setMoney(0);
		}
		else {
			pandon.push_back(temp_money);
			this->setMoney(this->getMoney() - temp_money);
		}
		break;

	case 5://Ç®: ±ò¸° µ·¸¸Å­ º£ÆÃ
		temp_money = 0;
		for (int i = 0; i < pandon.size(); i++) {
			temp_money += pandon[i];//±ò¸°µ· °è»ê
		}

		if (temp_money > this->getMoney()) { //ÀÜ°íº¸´Ù ³»·Á´Â µ·ÀÌ ¸¹Àº °æ¿ì, ÀÜ°í±Ý¾×¸¸ ÀüºÎ betting
			pandon.push_back(this->getMoney());
			this->setMoney(0);
		}
		else {
			pandon.push_back(temp_money);
			this->setMoney(this->getMoney() - temp_money);
		}
		break;

	case 3://Ã¼Å©: 
	default:
		break;
	}

	int pd = 0;
	for (int i = 0; i < pandon.size(); i++) {
		pd += pandon[i];//±ò¸°µ· °è»ê
	}

	return pd; //ÇöÀç ÆÇµ·À» ¹ÝÈ¯
}

