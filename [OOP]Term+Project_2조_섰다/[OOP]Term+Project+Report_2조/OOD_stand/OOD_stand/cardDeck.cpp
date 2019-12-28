#include "pch.h"
#include "cardDeck.h"
#include<vector>
#include<random>
#include <string>
#include <chrono>
#include <algorithm>
using namespace std;

cardDeck::cardDeck() {
	for (int i = 1; i < 21; i++) {
		this->cd.push_back(i);
	}
}


cardDeck::~cardDeck()
{
}

void cardDeck::init() { // 카드 집 초기화
	for (int i = 0; i < cd.size(); i++) {
		this->cd[i] = i + 1;
	}
	for (int i = cd.size(); i < 20; i++) {
		this->cd.push_back(i + 1);
	}
}

void cardDeck::cd_shuffle() {
	std::random_device rd;
	std::mt19937 g(rd());

	shuffle(cd.begin(), cd.end(), g);   //card deck을 만들어서 섞어준다.
}

int cardDeck::Size() {
	return cd.size();
}

int cardDeck::cdmember(int i) {
	return cd[i];
}

int cardDeck::popCard() {
	int tmp = cd[cd.size() - 1];
	cd.pop_back();

	return tmp;
}