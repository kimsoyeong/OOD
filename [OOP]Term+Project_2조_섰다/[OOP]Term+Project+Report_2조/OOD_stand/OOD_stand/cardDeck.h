#pragma once
#include <vector>
using namespace std;

class cardDeck
{
	vector<int> cd;

public:
	cardDeck();
	~cardDeck();
	void cd_shuffle();
	void init();
	int Size();
	int cdmember(int i);
	int popCard();
};
