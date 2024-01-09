#include <utility>
#include "Order.h"

Order::Order() {
	total = 0.0;
	vector <Item*> order;
}
pair<string, string> Order::calculateTotal() {
	int discount = 0;
	double savings = 0;
	for (int i = 0; i < order.size(); ++i) {
		total += order[i]->price;
		if (Appetiser* appItem = dynamic_cast<Appetiser*>(order[i])) {	//Checks if item is appetiser
			if (appItem->twoForOne) {	//checks if 241 = true
				discount += 1;		//adds discount if there is 2
				if (discount == 2) {
					total -= order[i]->price;
					savings += order[i]->price;
					discount = 0;
				}
				else if (discount > 2) {
					discount = 0;
				}
				
			}
		}
	}
	string totalStr = to_string(total);		//Formatting for price
	totalStr = totalStr.substr(0, totalStr.length() - 4);
	cout << "Current total is: " << totalStr << endl;

	string savingsStr = to_string(savings);		//Formatting for savings
	savingsStr = savingsStr.substr(0, savingsStr.length() - 4);
	return make_pair(totalStr, savingsStr);
}
string Order::toString() {
	string orderStr;
	for (int i = 0; i < order.size(); ++i) {
		orderStr += "(" + to_string(i + 1) + ") " + order[i]->toString() + "\n";		
	}
	pair <string, string> values = calculateTotal();
	orderStr += "Savings: " + values.second +"\n";
	orderStr += "Price: " + values.first + "\n";
	return orderStr;
}

void Order::remove(Item* choice) {
	auto it = find(order.begin(), order.end(), choice);
	order.erase(it);
	cout << "Removed Item from order";
}

void Order::add(Item* choice) {
	order.push_back(choice);
	cout << "Added Item to order" << endl;
}

void Order::printReceipt() {
	ofstream outputFile("receipt.txt");
	if (outputFile.is_open()) {
		outputFile << toString(); // Write the string content to the file
		outputFile.close(); // Close the file
		std::cout << "receipt created successfully." << std::endl;
	}
	else {
		std::cout << "Unable to create/open the file." << std::endl;
	}
}

Item* Order::getIndex(int index) {
	if (index >= 0 && index <= order.size()) {
		return order[index];
	}
	else {
		cout << "Invalid item number" << endl;
		return nullptr;
	}
}
