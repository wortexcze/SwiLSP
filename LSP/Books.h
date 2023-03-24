#pragma once

#include <iostream>
#include "Settings.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Books
{
	int id;			// Primary Key
	string name;
	string auth;
	int price;
	int qty;
public:
	void add();
	void update_price();
	void search();
	void update();
	void display();
};

