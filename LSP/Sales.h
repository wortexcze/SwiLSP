#pragma once
#include "Date.h"
#include <iostream>
#include "Settings.h"
#include "Books.h"
using std::cout;
using std::endl;
using std::string;
using std::cin;

class Sales
{
	int invoice_id;		//Primary key
	int member_id;		//FK ref member(id)
	int book_id;		//FK ref books(id)
	int qty;
	int amount;
	date date_s;
public:
	void add();
	void find_total_sales();

	//start demeter
	void find_all_salesbyAuthorId(Books a) const;
};

