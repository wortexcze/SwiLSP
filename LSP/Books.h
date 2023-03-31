#pragma once

#include <iostream>
#include "Settings.h"
#include "Employees.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Books
{
	int id;			// Primary Key
	string name;
	Person* author;
	int price;
	int qty;
public:
	void add();
/*	void update_price(); */
	void search();
	/*void update(); */
	void display();

	//pro demeter
	Person* GetAuthor() const;

};

