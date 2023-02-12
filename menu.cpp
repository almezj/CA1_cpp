#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <list>
#include <unordered_set>
#include <unordered_map>

using namespace std;

/*
This program was made with these assumptions:
	1. The input file is in the same directory as "menu.cpp" file.
	2. The input file is NOT empty.
	3. Program is compiled using C++11 or higher.
*/

struct shipmentData
{
	int id;
	char warehouse_block;
	string mode_of_shipment;
	int customer_care_calls;
	int customer_rating;
	int cost_of_the_product;
	int prior_purchases;
	string product_importance;
	char gender;
	int discount_offered;
	int weight_in_gms;
	int reached_on_time;
};

void display(const shipmentData &ship)
{
	cout << left
		 << setw(15) << ship.id
		 << setw(15) << ship.warehouse_block
		 << setw(15) << ship.mode_of_shipment
		 << setw(15) << ship.customer_care_calls
		 << setw(15) << ship.customer_rating
		 << setw(15) << ship.cost_of_the_product
		 << setw(15) << ship.prior_purchases
		 << setw(15) << ship.product_importance
		 << setw(15) << ship.gender
		 << setw(15) << ship.discount_offered
		 << setw(15) << ship.weight_in_gms
		 << setw(15) << ship.reached_on_time

		 << endl;
}

void showHeaders()
{
	cout << left
		 << setw(15) << "ID"
		 << setw(15) << "Block"
		 << setw(15) << "Mode"
		 << setw(15) << "CC Calls"
		 << setw(15) << "C Rating"
		 << setw(15) << "CoP"
		 << setw(15) << "Prior Purchases"
		 << setw(15) << "Importance"
		 << setw(15) << "Gender"
		 << setw(15) << "Discount"
		 << setw(15) << "Weight"
		 << setw(15) << "On Time"
		 << endl;
}

void checkForInvalidProductImportanceValues(list<shipmentData> &shiplist, unordered_set<string> &importanceSet)
{
	list<shipmentData>::iterator it;
	cout<<"Products with invalid importance values: "<<endl;
	for (it = shiplist.begin(); it != shiplist.end(); it++)
	{
		if (importanceSet.find(it->product_importance) == importanceSet.end())
		{
			cout << it->id << " " << it->product_importance << endl;
		}
	}
}

bool sortCost(const shipmentData &a, const shipmentData &b)
{
	return a.cost_of_the_product < b.cost_of_the_product;
}

bool sortID(const shipmentData &a, const shipmentData &b)
{
	return a.id < b.id;
}

shipmentData newShipment(shipmentData &ship){
	cout << "Enter ID: ";
	cin >> ship.id;
	cout << "Enter Block: ";
	cin >> ship.warehouse_block;
	cout << "Enter Mode: ";
	cin >> ship.mode_of_shipment;
	cout << "Enter CC Calls: ";
	cin >> ship.customer_care_calls;
	cout << "Enter C Rating: ";
	cin >> ship.customer_rating;
	cout << "Enter CoP: ";
	cin >> ship.cost_of_the_product;
	cout << "Enter Prior Purchases: ";
	cin >> ship.prior_purchases;
	cout << "Enter Importance: ";
	cin >> ship.product_importance;
	cout << "Enter Gender";
	cin >> ship.gender;
	cout << "Enter Discount";
	cin >> ship.discount_offered;
	cout << "Enter Weight";
	cin >> ship.weight_in_gms;
	cout << "Reached on time? (1/0)";
	cin >> ship.reached_on_time;
	return ship;
}

void llFeatures(list<shipmentData> &shiplist)
{
	cout << "Linked List Features" << endl;
	cout << "1. Display Linked-List Elements" << endl;
	cout << "2. Display Front Element" << endl;
	cout << "3. Display Last Element" << endl;
	cout << "4. Find Element by ID" << endl;
	cout << "5. Delete First Element" << endl;
	cout << "6. Delete Last Element" << endl;
	cout << "7. Delete Element at Nth Position" << endl;
	cout << "8. Insert Element at Nth Position" << endl;
	cout << "9. Count Customer Ratings" << endl;
	cout << "0. Sort by Customer Rating" << endl;

	int subchoice;
	cin >> subchoice;
	list<shipmentData>::iterator it;
	shipmentData ship;

	switch (subchoice)
	{
		if(cin.fail() || subchoice < 0 || subchoice > 9){
			cin.clear();
			cout<<"Invalid input. Please enter a valid option."<<endl;
		}
	case 1:
		showHeaders();
		for (it = shiplist.begin(); it != shiplist.end(); it++)
		{
			display(*it);
		}
		break;
	case 2:
		showHeaders();
		display(shiplist.front());
		break;
	case 3:
		showHeaders();
		display(shiplist.back());
		break;
	case 4:
		cout << "Enter ID to search for: ";
		int id;
		cin >> id;
		for (it = shiplist.begin(); it != shiplist.end(); it++)
		{
			if (it->id == id)
			{
				showHeaders();
				display(*it);
				break;
			}
			cout << "ID not found" << endl;
		}
		break;
	case 5:
		cout<< "Deleted first element" << endl;
		shiplist.pop_front();
		break;
	case 6:
		cout<< "Deleted last element" << endl;
		shiplist.pop_back();
		break;
	case 7:
		cout << "Enter position to delete: ";
		int pos;
		cin >> pos;
		it = shiplist.begin();
		advance(it, pos-1);
		if(it != shiplist.end()){
			shiplist.erase(it);
			cout << "Deleted element at position " << pos << endl;
		} else {
			cout << "Invalid position" << endl;
		}
		break;
	case 8:
		cout << "Enter position to insert: ";
		int pos2;
		cin >> pos2;
		it = shiplist.begin();
		if(pos2 > shiplist.size() || pos2 < 0){
			cout << "Invalid position" << endl;
			break;
		}
		advance(it, pos2);
		ship = newShipment(ship);
		shiplist.insert(it, ship);
		cout << "Inserted element at position " << pos2 << endl;
		break;
	default:
		break;
	}
}

void vecFeatures(list<shipmentData> &shiplist, vector<shipmentData> &vec){
	cout << "Vector Features" << endl;
	cout << "1. Populate Vector from the current Linked-list" << endl;
	cout << "2. Display All Elements" << endl;
	cout << "3. Display Element at Index position i" << endl;
	cout << "4. Insert New Shipping Record at position 2" << endl;
	cout << "5. Sort the Vector in order of Product Cost" << endl;
	cout << "6. Sort the vector in order of ID" << endl;
	cout << "7. Display shipping records where customer rating is less than 3" << endl;

	int subchoice;
	cin >> subchoice;
	shipmentData ship;
	list<shipmentData>::iterator it;

	if(cin.fail() || subchoice < 0 || subchoice > 7){
		cin.clear();
		cout<<"Invalid input. Please enter a valid option."<<endl;
	}
	
	switch (subchoice)
	{
	case 1:
		for (it = shiplist.begin(); it != shiplist.end(); it++)
		{
			vec.push_back(*it);
			cout << "Addded: " << it->id << endl;
		}
		break;
	case 2:
		showHeaders();
		for (int i = 0; i < vec.size(); i++)
		{
			display(vec[i]);
		}
		break;
	case 3:
		cout << "Enter index to display: ";
		int index;
		cin >> index;
		if(index > vec.size() || index < 0){
			cout << "Invalid index" << endl;
			break;
		}
		showHeaders();
		display(vec[index]);
		break;
	case 4:
		ship = newShipment(ship);
		vec.insert(vec.begin() + 2, ship);
		cout << "Inserted new shipping record at position 2" << endl;
		break;
	case 5:
		sort(vec.begin(), vec.end(), sortCost);
		cout << "Vector sorted by cost" << endl;
		break;

	case 6:
		sort(vec.begin(), vec.end(), sortID);
		cout << "Vector sorted by ID" << endl;
		break;
	case 7:
		showHeaders();
		for (int i = 0; i < vec.size(); i++)
		{
			if (vec[i].customer_rating < 3)
			{
				display(vec[i]);
			}
		}
		break;
	default:
		break;
	}
}

void setFeatures(list<shipmentData> &shiplist, unordered_set<string> &uos){
	cout << "Set Features" << endl;
	cout << "1. Check that all Shipping Records have valid Product Importance" << endl;

	int subchoice;
	cin >> subchoice;
	

	uos.insert("low");
	uos.insert("medium");
	uos.insert("high");

	if(subchoice != 1){
		cin.clear();
		cout<<"Invalid input. Please enter a valid option."<<endl;
	}
	

	switch (subchoice)
	{
	case 1:
		checkForInvalidProductImportanceValues(shiplist, uos);
		break;
	
	default:
		break;
	}
}

void mapFeatures(list<shipmentData> &shiplist, unordered_map<int, shipmentData> &uom){
	cout << "Map Features" << endl;
	cout << "1. Find and Display a record by ID" << endl;

	int subchoice;
	cin >> subchoice;
	list<shipmentData>::iterator it;

	for(shipmentData i: shiplist){
		uom[i.id] = i;
	}

	if(subchoice != 1){
		cin.clear();
		cout<<"Invalid input. Please enter a valid option."<<endl;
	}

	switch (subchoice)
	{
	case 1:
		cout << "Enter ID to find: ";
		int id;
		cin >> id;
		if(uom.find(id) != uom.end()){
			showHeaders();
			display(uom[id]);
		} else {
			cout << "ID not found" << endl;
		}
		break;
	default:
		break;
	}
}

void menu(list<shipmentData> &shiplist, vector<shipmentData> &vec, unordered_set<string> &uos, unordered_map<int, shipmentData> &uom)
{
	cout << "1. Linked-List Features" << endl;
	cout << "2. Vector Features" << endl;
	cout << "3. Set Features" << endl;
	cout << "4. Map Features" << endl;
	cout << "5. Quit" << endl;

	int choice;
	cin >> choice;

	if(cin.fail() || choice < 0 || choice > 9){
		cin.clear();
		cout<<"Invalid input. Please enter a valid option."<<endl;
	}

	switch (choice)
	{
	case 1:
		llFeatures(shiplist);
		break;
	case 2:
		vecFeatures(shiplist, vec);
		break;
	case 3:
		setFeatures(shiplist, uos);
		break;
	case 4:
		mapFeatures(shiplist, uom);
		break;
	case 5:
		cout << "Thank you for using the program" << endl;
		break;
	default:
		break;
	}
}

void parseLine(string line, shipmentData &sd)
{
	string temp;

	try
	{
		stringstream ss(line);

		getline(ss, temp, ',');

		sd.id = stoi(temp);
		getline(ss, temp, ',');
		// Stores first character of temp field
		sd.warehouse_block = temp[0];
		getline(ss, sd.mode_of_shipment, ',');

		getline(ss, temp, ',');

		sd.customer_care_calls = stoi(temp);

		getline(ss, temp, ',');

		sd.customer_rating = stoi(temp);

		getline(ss, temp, ',');

		sd.cost_of_the_product = stoi(temp);

		getline(ss, temp, ',');

		sd.prior_purchases = stoi(temp);
		getline(ss, sd.product_importance, ',');

		getline(ss, temp, ',');
		// Stores first character of temp field
		sd.gender = temp[0];

		getline(ss, temp, ',');

		sd.discount_offered = stoi(temp);

		getline(ss, temp, ',');

		sd.weight_in_gms = stoi(temp);

		getline(ss, temp, ',');

		sd.reached_on_time = stoi(temp);
	}
	catch (std::invalid_argument const &e)
	{
		cout << "Error" << endl;
		cout << e.what() << endl;
		cout << temp << endl;
	}
}

void load(string fname, list<shipmentData> &data)
{
	ifstream fin(fname);

	if (fin)
	{
		string line;
		getline(fin, line);
		while (getline(fin, line))
		{
			shipmentData ship;
			parseLine(line, ship);
			data.push_back(ship);
		}
		fin.close();
	}
	else
	{
		cout << "Error opening file." << endl;
	}
}

int main()
{
	bool inApp = true;
	list<shipmentData> shiplist;
	vector<shipmentData> vec;
	unordered_map <int, shipmentData> uom;
	unordered_set <string> uos;
	load("shipping-data-large.csv", shiplist);

	while(inApp){

		cout << "Welcome to the Shipping Data Analysis Program" << endl;
		menu(shiplist, vec, uos, uom);
		cout << "Would you like to continue? (y/n)" << endl;
		char choice;
		cin >> choice;
		if(choice == 'n'){
			inApp = false;
		}
	}

	return 0;
}