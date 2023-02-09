#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

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

void llfeatures(list<shipmentData> shiplist)
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
		advance(it, pos);
		shiplist.erase(it);
		cout << "Deleted element at position " << pos << endl;
		break;
	case 8:
		cout << "Enter position to insert: ";
		int pos2;
		cin >> pos2;
		it = shiplist.begin();
		advance(it, pos2);
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
		cout << "Enter Gender: ";
		cin >> ship.gender;
		cout << "Enter Discount: ";
		cin >> ship.discount_offered;
		cout << "Enter Weight: ";
		cin >> ship.weight_in_gms;
		cout << "Enter On Time: ";
		cin >> ship.reached_on_time;
		shiplist.insert(it, ship);
		cout << "Inserted element at position " << pos2 << endl;
		break;
	default:
		break;
	}
}

void menu(list<shipmentData> shiplist)
{
	cout << "Welcome to the Shipping Data Analysis Program" << endl;
	cout << "1. Linked-List Features" << endl;
	cout << "2. Vector Features" << endl;
	cout << "3. Set Features" << endl;
	cout << "4. Map Features" << endl;
	cout << "5. Quit" << endl;

	int choice;
	cin >> choice;

	//FIXME: If choice is not an integer, the program will loop infinitely

	//TODO: Add vecfeatures(), setfeatures(), and mapfeatures() functions
	switch (choice)
	{
	case 1:
		llfeatures(shiplist);
		break;
	case 2:
		/* vecfeatures(); */
		break;
	case 3:
		/* setfeatures(); */
		break;
	case 4:
		/* mapfeatures(); */
		break;
	case 5:
		cout << "Thank you for using the program" << endl;
		break;
	default:
		cout << "Invalid choice" << endl;
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
	load("shipping-data-small.csv", shiplist);

	while(inApp){

		menu(shiplist);
		cout << "Would you like to continue? (y/n)" << endl;
		char choice;
		cin >> choice;
		if(choice == 'n'){
			inApp = false;
		}
	}
	

	/* display(*shiplist.begin()); */

	return 0;
}