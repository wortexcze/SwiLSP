#pragma once
#include <iostream>
#include "Date.h"
#include "Person.h"
#include "Settings.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

class Employees:public Person
{
private:
	int id;		// Primary Key
	date date_of_joining;
	long int salary;
	string mgr_status;	// Check (T or F) def F
public:
	int getId() { return id; }
	void add_emp();
	void search_emp();
	void assign_mgr_stat();
	void display();
	void update_sal();
};

