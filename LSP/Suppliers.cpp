#include "Suppliers.h"

void Suppliers::add_sup()
{
	cout << "Enter the Supplier Name : ";
	cin >> name;
	cout << "Enter Phone no. : ";
	cin >> phn;
	cout << "Enter the address (in 3 lines) : ";
	cin >> addr_line1;
	cin >> addr_line2;
	cin >> addr_city;
	cout << "Enter State : ";
	cin >> addr_state;
	stmt.str("");
	stmt << "Insert into suppliers(name,phone_no,addr1,addr2,addr_city,addr_stat) values('" << name << "'," << phn << ",'" << addr_line1 << "','" << addr_line2 << "','" << addr_city << "','" << addr_state << "');";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if (!(res_set))
		cout << endl << endl << "Supplier Record Inserted Successfully" << endl << endl << endl;
	else
		cout << endl << endl << "Entry ERROR !" << endl << "Contact Technical Team " << endl << endl << endl;
}

void Suppliers::remove_supplier()
{
	cout << "Enter the supplier id to remove the Supplier : ";
	cin >> id;
	stmt.str("");
	stmt << "Delete from suppliers where id = " << id << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	cout << "Supplier Removed.";
}

void Suppliers::search_id()
{
	cout << "Enter the supplier id to find the Supplier details : ";
	cin >> id;
	stmt.str("");
	stmt << "Select * from suppliers where id = " << id << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if ((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << "Details of Supplier Id : " << row[0] << endl;
		cout << "Name : " << row[1] << endl;
		cout << "Phone no. : " << row[2] << endl;
		cout << "Address Line 1 : " << row[3] << endl;
		cout << "Address Line 2 : " << row[4] << endl;
		cout << "City : " << row[5] << endl;
		cout << "State : " << row[6] << endl;
	}
	else
	{
		cout << "No Supplier Found!!";
	}
}

