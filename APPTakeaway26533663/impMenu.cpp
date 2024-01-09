#include "Menu.h"

Menu::Menu(const string& filename) {

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file " << filename << endl;
        return;
    }

    string line;    //Stores single lines as strings
    while (getline(file, line)) {   //reads lines from file into line until there are no more to read
        if (line.empty())
            continue;

        vector<string> data;    //Vector of strings to hold values from each line
        string item;    //substring of line which holds value for certain column
        size_t start = 0;   //start of substring is initially first character in string
        size_t pos = line.find(',');    //Position of comma in line

        while (pos != string::npos) {   //While there are commas to find (npos is error for no found string)
            item = line.substr(start, pos - start); //Extract value as substring comparing start position and current position
            data.push_back(item);   //adds item to data
            start = pos + 1;    //start is now the past found comma
            pos = line.find(',', start);    //pos is the first comma from the start position
        }

        data.push_back(line.substr(start)); // Last piece of data after last comma

        if (data.size() < 7) {
            cerr << "Incomplete data in line: " << line << endl; //not all categories filled, show error
            continue;
        }

        string category = data[0];  //First column is category
        string name = data[1];  //second is name
        string price = data[2]; //then price
        string cal = data[3];   //then calories
        string shareable = data[4]; //then is it shareable
        string twoForOne = data[5]; //then is it 2 for 1
        string volume = data[6];    //drink volume
        string abv;
        if (data.size() > 7) {
            abv = data[7];  // Extract the ABV value
        }
        else {
            abv = "";   // Set an empty string if the ABV is missing
        }

        if (category == "a") { // Appetisers
            
            bool isShareable = (shareable == "y");  //y = yes = true
            bool isTwoForOne = (twoForOne == "y");  //y = yes = true
            Appetiser* newItem = new Appetiser(category, name, stoi(cal), stod(price), isShareable, isTwoForOne); //Creates new appetiser if line is appetiser
            itemList.push_back(newItem); // Add to itemList
            
        }
        else if (category == "m") { // Main dishes
            
            MainCourse* newItem = new MainCourse(category, name, stoi(cal), stod(price)); //Creates new maincourse if line is maincourse
            itemList.push_back(newItem); // Add to itemList
            
        }
        else if (category == "b") { // Beverages
            ;
            double bevABV = 0.0;
            if (!abv.empty()) {
                bevABV = stod(abv);
            }
            Beverage* newItem = new Beverage(category, name, stoi(cal), stod(price), stoi(volume), bevABV);//Creates new beverage if line is beverage
            itemList.push_back(newItem); // Add to itemList
            
        }
    }

    file.close();
}

string Menu::toString() {
        string menuString;
        int i;
        bool header2 = false;
        bool header3 = false;
        string strHeader2 = "----------Main Course----------\n";    //MC header
        string strHeader3 = "----------Beverages----------\n";  //Beverages Header
        menuString += "----------Appetisers----------\n";   //Appetiser header printed first by default
        for (i = 0; i < itemList.size(); ++i) { //For i in itemlist...
            if (itemList[i]->category == "m") { //if cat is m print mc header
                if (!header2) {
                    header2 = true; //Set header as true (printed)
                    menuString += strHeader2;
                }
            }
            if (itemList[i]->category == "b") { //Same for beverages header
                if (!header3) {
                    header3 = true;
                    menuString += strHeader3;
                }
            }
            menuString += "(" + to_string(i + 1) + ") " + itemList[i]->toString() + "\n";   //Print toString()'s of respective objects
 
        }
        return menuString;
}

Item* Menu::getIndex(int index) {
    if (index >= 0 && index <= itemList.size()) {
        return itemList[index];
    }
    else {
        cout << "Invalid item number" << endl;
        return nullptr;
    }
}