#pragma once
#include "Item.h"

class Appetiser : public Item {
public:
	Appetiser(string category, string n, int c, double p, bool s, bool t);
	~Appetiser();
	string toString() const override;
	bool twoForOne;
private:
	bool shareable;
	
};