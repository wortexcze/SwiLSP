#pragma once
#include <iostream>
#include "Date.h"
#include "Person.h"
#include "Settings.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Members:public Person
{
private:
	int id;		// Primary Key
	date beg_date;
	date end_date;
	string valid;
public:
	 int getId() const { return id; }
     void add_mem();
	 void refresh();
	 void search_mem();
};

