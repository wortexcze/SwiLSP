#include "Members.h"
void Members::add_mem() override
{
	cout << "Enter the name of the member : ";
	cin >> name;
	cout << "Enter phone no. : ";
	cin >> phn;
	cout << "Enter address (in 3 lines)" << endl;
	cin >> addr_line1;
	cin >> addr_line2;
	cin >> addr_city;
	cout << "Enter the name of the state : ";
	cin >> addr_state;
	stmt.str("");
	stmt << "insert into members(name,addr1,addr2,addr_city,addr_stat,phone_no,beg_date,end_date) values ('" << name << "','" << addr_line1 << "','" << addr_line2 << "','" << addr_city << "','" << addr_state << "'," << phn << ",curdate(),Date_add(curdate(), INTERVAL 1 YEAR));";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	// fetching member id...
	stmt.str("");
	stmt << "Select id from members where phone_no = " << phn << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	row = mysql_fetch_row(res_set);
	cout << endl << endl << endl << endl;
	cout << "Member Added successfully" << endl << endl << "Member Id : " << row[0];
	cout << endl << endl << endl << endl;
}


void Members::refresh()
{
	query = "Update members set valid = 'invalid' where end_date <= curdate();";
	q = query.c_str();
	mysql_query(conn, q);
}

void Members::search_mem()
{
	cout << "Enter member id : ";
	cin >> id;
	stmt.str("");
	stmt << "Select * from members where id  = " << id << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if ((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << "Member Details" << endl;
		cout << "Name : " << row[1] << endl;
		cout << "Address : " << endl << row[2] << endl << row[3] << endl << row[4] << endl;
		cout << "State : " << row[5] << endl;
		cout << "Contact no. : " << row[6] << endl;
		cout << "Membership begin date : " << row[7] << endl;
		cout << "Membership end date  : " << row[8] << endl;
		cout << "Membership Status : " << row[9] << endl << endl << endl;
	}
	else
	{
		cout << "No Member Found!!" << endl << endl << endl;
	}
}
