#include "Sales.h"


void Sales::add()
{
	cout << "Enter Menber id :";
	cin >> member_id;
	cout << "Enter the book id : ";
	cin >> book_id;
	cout << "Enter the quantity : ";
	cin >> qty;
	stmt.str("");
	stmt << "select price*" << qty << " from books where id = " << book_id << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if ((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << "The bill amount : " << row[0] << endl << endl;
		amount = (int)row[0];
	}
	else
	{
		cout << "Book Id invalid!!" << endl;
		getch();
		return;
	}
	stmt.str("");
	stmt << "insert into sales(mem_id,book_id,qty,amt,sales_date) values (" << member_id << "," << book_id << "," << qty << "," << amount << ",curdate());";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	// fetching invoice id...
	stmt.str("");
	stmt << "select inv_id from sales where mem_id = " << member_id << " AND book_id = " << book_id << " AND qty = " << qty << " AND sales_date = curdate();";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if ((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << "The Invoice id for the bill is " << row[0] << endl << endl << endl;
	}
	else
	{
		cout << "The entered details maybe wrong." << endl << "Please Recheck and Enter again" << endl << endl << endl;
	}
}


void Sales::find_total_sales()
{
	query = "select sum(amt) from sales where year(sales_date) = year(curdate());";
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if ((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << "Total sales this year : " << row[0] << endl << endl << endl << endl;
	}
}

void Sales::find_all_salesbyAuthorId(Books a) const{

	int id = a.GetauthorId();

	
	query = "select mem_id,book_id,qty,amt,sales_date  from sales where book_id"+id;
	q = query.c_str();

	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if ((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << "member id:" << row[0] <<"," << "book id:" << row[1] << "," << "qty:" << row[2] << "," << "amt:" << row[3] <<"," << "sales_date :" << row[4] << endl;
	}
	else
	{
		cout << "The entered details maybe wrong." << endl << "Please Recheck and Enter again" << endl << endl << endl;
	}



}
