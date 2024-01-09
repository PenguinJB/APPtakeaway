#include "Beverage.h"

Beverage::Beverage(string cat, string n, int c, double p, int v, double a) {
	name = n;
	calories = c;
	price = p;
	abv = a;
	volume = v;
	category = cat;
}

Beverage::~Beverage() {
	cout << "Removed Item: " << name << endl;
}

string Beverage::toString() const {
	string priceStr = to_string(price);
	priceStr = priceStr.substr(0, priceStr.length() - 4);
	string abvStr = to_string(abv);
	abvStr = abvStr.substr(0, abvStr.length() - 5);
	string bevString = name + ": " + priceStr + ", " + to_string(calories) + "cal (" + to_string(volume) + "ml)";
	if (isAlcoholic()) {
		bevString += ", " + abvStr + "% abv)";
	}
	return bevString;
}

bool Beverage::isAlcoholic() const {
	return (abv > 0.0);
}