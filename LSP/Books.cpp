#include "Books.h"

void Books::add()
{
	cout << "Enter the name of the book : ";
	cin >> name;
	cout << "Enter the name of the author : ";
	cin >> auth;
	cout << "Enter the Price : ";
	cin >> price;
	cout << "Enter the Qty Recived : ";
	cin >> qty;
	stmt.str("");
	stmt << "Insert into books(name,auth,price,qty) values('" << name << "','" << auth << "'," << price << "," << qty << ");";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if (!(res_set))
		cout << endl << endl << "Book Record Inserted Successfully" << endl << endl << endl;
	else
		cout << endl << endl << "Entry ERROR !" << endl << "Contact Technical Team " << endl << endl << endl;
}
/**/
void Books::update_price()
{
	char choice;
	cout << "Enter the id of the book for update in price : ";
	cin >> id;
	stmt.str("");
	stmt << "Select name,price from books where id = " << id << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if ((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << "The Name of the book is : " << row[0] << endl;
		cout << "The current price of the book is : " << row[1] << endl;
		cout << "Do you Want to Update the Price [y/n] : ";
		cin >> choice;
		if (choice == 121 || choice == 89)
		{
			cout << "Enter the new price : ";
			cin >> price;
			stmt.str("");
			stmt << "Update books set price = " << price << " where id = " << id << ";";
			res_set = mysql_store_result(conn);
			if (!(res_set))
				cout << endl << endl << "Book Price Updated Successfully" << endl << endl << endl;
			else
				cout << endl << endl << "Entry ERROR !" << endl << "Contact Technical Team " << endl << endl << endl;
		}
		else
		{
			cout << "No changes Made!!";
		}
	}
	else
	{
		cout << "No Book found!!!";
	}
}
*/

void Books::search()
{
	cout << "Enter book id for details : ";
	cin >> id;
	stmt.str("");
	stmt << "Select * from books where id = " << id << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if ((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << "The Details of Book Id " << row[0] << endl;
		cout << "The Name of the book is : " << row[1] << endl;
		cout << "THE Author of " << row[1] << " is " << row[2] << endl;
		cout << "The Price of the book is : " << row[3] << endl;
		cout << "The inventory count is " << row[4] << endl;
	}
	else
	{
		cout << "No record Found" << endl;
	}
}

/*
void Books::update()
{
	int b_id[100], qty[100], i = 0, max;
	stmt.str("");
	stmt << "Select book_id,qty from purchases where recieves = 'T' and inv IS NULL;";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	stmt.str("");
	stmt << "Update purchases set inv = 1 where recieves = 'T' and inv IS NULL;";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	while ((row = mysql_fetch_row(res_set)) != NULL)
	{
		b_id[i] = (int)row[0];
		qty[i] = (int)row[1];
		i++;
	}
	max = i;
	for (i = 0; i <= max; i++)
	{
		stmt.str("");
		stmt << "update books set qty = " << qty[i] << " where id = " << b_id[i] << ";";
		query = stmt.str();
		q = query.c_str();
		mysql_query(conn, q);
	}
	cout << "The orders recieved have been updated.";
}*/

void Books::display()
{
	int i = 0;
	query = "Select * from books;";
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	while ((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << "Name for book " << ++i << " : " << row[1] << endl;
		cout << "Name of Author : " << row[2] << endl;
		cout << "Price : " << row[3] << endl;
		cout << "Quantity : " << row[4] << endl;
		cout << endl << endl << endl << endl;
	}
}


Person* Books::GetAuthor() const {
	return this->author;
}

