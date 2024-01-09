/*
Item Class
Parent Class for Appetiser, MainCourse, Beverage
Contains public methods for toString
toString is virtual overriden by each child, to account for varying details (Abv/Shareable etc)
contains protected variables for calories, name, price. All required to be accessed by child classes
*/

#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Item {
public:
	Item() : name(""), calories(0), price(0.0) {} // Default constructor
	~Item(); // Destructor || Outputs message with "Item removed" itemname
	Item(string cat, string n, int c, double p); // Constructor taking name, calories, price as n, c, p respectively
									 // Also used for MainCourse
	virtual string toString() const;		// Virtual toString() overriden by each child class
	string category;
	double price;
protected:
		string name;
		int calories;	//Calories, name, price variables to be accessed by child class
				
};

