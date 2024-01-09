#include "Appetiser.h"

Appetiser::Appetiser(string cat, string n, int c, double p, bool s, bool t) {
	name = n;
	calories = c;
	price = p;
	shareable = s;
	twoForOne = t;
	category = cat;
}

Appetiser::~Appetiser() {
	cout << "Removed Item: " << name << endl;
}

string Appetiser::toString() const {
	string priceStr = to_string(price);
	priceStr = priceStr.substr(0, priceStr.length() - 4);
	string appString = name + ": " + priceStr + ", " + to_string(calories) + "cal";
	if (shareable)
		appString += " (shareable)";
	if (twoForOne)
		appString += " (2-4-1)";
	return appString;
}