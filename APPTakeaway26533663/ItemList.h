#pragma once
#include <vector>
#include "Item.h"
#include "Appetiser.h"
#include "MainCourse.h"
#include "Beverage.h"
using namespace std;

class itemList {
public:
	vector <Item*> itemList;
	virtual string toString() = 0;
};