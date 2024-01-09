/*
	Implementation for Item Class
	Contains definition for toString method
	uses string stream to output menu line for item
*/

#include "Item.h"

Item::Item(string cat, string n, int c, double p) {	//Constructor sets values for...
	name = n;		//Name
	calories = c;	//Calories
	price = p;		//Price
	category = cat;	//Category
}
Item::~Item() {	//Destructor shows destruction message for deletion in order
	cout << "Item Removed: " << name << endl;
}


string Item::toString() const {
	string priceStr = to_string(price);
	priceStr = priceStr.substr(0, priceStr.length() - 4);
	string itemString = name + ": " + priceStr + ", " + to_string(calories) + "cal";
	return itemString;
}
