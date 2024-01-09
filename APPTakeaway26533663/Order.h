#pragma once
#include "ItemList.h"
#include "Menu.h"

class Order : public itemList {
public:
	Order();
	pair<string, string> calculateTotal();
	void printReceipt();
	string toString() override;
	void remove(Item* choice);
	void add(Item* choice);
	Item* getIndex(int index);
private:
	vector <Item*> order;
	double total;
}; 