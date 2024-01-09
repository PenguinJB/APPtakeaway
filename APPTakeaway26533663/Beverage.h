#pragma once
#include "Item.h"

class Beverage : public Item {
public:
	Beverage(string cat, string n, int c, double p, int v, double a);
	~Beverage();
	string toString() const override;
	bool isAlcoholic() const;
private:
	double abv;
	int volume;
};