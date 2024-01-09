#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "ItemList.h"


class Menu : public itemList {
public:
    Menu(const string& filename);
    string toString() override;
    Item* getIndex(int index);
};
