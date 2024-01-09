#include "MainCourse.h"

MainCourse::MainCourse(string cat, string n, int c, double p) {
	name = n;
	calories = c;
	price = p;
	category = cat;
}
MainCourse::~MainCourse() {
	cout << "Item Removed: " << name << endl;
}
string MainCourse::toString() const {
	string priceStr = to_string(price);
	priceStr = priceStr.substr(0, priceStr.length() - 4);
	string MCString = name + ": " + priceStr + ", " + to_string(calories) + "cal";
	return MCString;
}