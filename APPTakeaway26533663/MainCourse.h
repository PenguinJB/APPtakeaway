#pragma once
#include "Item.h"

class MainCourse : public Item {
public:
	MainCourse(string cat, string n, int c, double p);
	~MainCourse();
	string toString() const override;

};