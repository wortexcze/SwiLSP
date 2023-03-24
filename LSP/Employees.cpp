#include "Employees.h"

void Employees::add_emp()
{
	cout << "Enter Your Id for verification : ";
	cin >> id;
	stmt.str("");
	stmt << "Select mgr_stat from employees where id  = " << this->getId() << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if ((row = mysql_fetch_row(res_set)) == NULL)
	{
		cout << "Employee Not Found!!" << endl << endl << endl;
		return;
	}
	else
	{
		mgr_status = (char*)row[0];
		if (mgr_status == "T")
		{
			cout << "You Do Not have Manager Rights!!!" << endl << endl;
			return;
		}
	}
	cout << "Enter The details of new employees!!";
	cout << "Enter The name of the employee : ";

	string tmp;

	cin >> tmp;
	this->setName(tmp);
	cout << "Enter the Address (in 3 lines) : " << endl;
	tmp = "";
	cin >> tmp;
	this->setAddrLine1(tmp);
	cin >> addr_line2;
	cin >> addr_city;
	cout << "Enter State : ";
	cin >> addr_state;
	cout << "Enter phone no.";
	cin >> phn;
	cout << "Enter the salary : ";
	cin >> salary;
	stmt.str("");
	stmt << "Insert into employees (name,addr1,addr2,addr_city,addr_stat,phone_no,doj,salary) values ('" << name << "','" << addr_line1 << "','" << addr_line2 << "','" << addr_city << "','" << addr_state << "'," << phn << ",curdate()," << salary << ");";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	cout << endl << endl << "Employee Added Succesfully!" << endl << endl << endl;
}


void Employees::assign_mgr_stat()
{
	cout << "Enter Your Id for verification : ";
	cin >> id;
	stmt.str("");
	stmt << "Select mgr_stat from employees where id  = " << id << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if ((row = mysql_fetch_row(res_set)) == NULL)
	{
		cout << "Employee Not Found!!" << endl << endl << endl;
		return;
	}
	else
	{
		mgr_status = (char*)row[0];
		if (mgr_status == "T")
		{
			cout << "You Do Not have Manager Rights!!!" << endl << endl;
			return;
		}
	}
	cout << "Enter the employee id to grant Manager status : ";
	cin >> id;
	stmt.str("");
	stmt << "update employees set mgr_stat = 'T' where id = " << id << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	cout << endl << endl << endl;
	cout << "Manager Status granted";
	cout << endl << endl << endl;
}

void Employees::search_emp()
{
	cout << "Enter the id for searching an employee : ";
	cin >> id;
	stmt.str("");
	stmt << "Select * from employees where id  = " << id << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if ((row = mysql_fetch_row(res_set)) != NULL)
	{
		cout << "Employees Details" << endl;
		cout << "Name : " << row[1] << endl;
		cout << "Address : " << endl << row[2] << endl << row[3] << endl << row[4] << endl;
		cout << "State : " << row[5] << endl;
		cout << "Contact no. : " << row[6] << endl;
		cout << "Date of Joining" << row[7] << endl;
		cout << "Salary : " << row[8] << endl << endl << endl;
	}
	else
	{
		cout << "No Employee Found!!" << endl << endl << endl;
	}
}

void Employees::display()
{
	int i = 0;
	query = "Select * from employees;";
	q = query.c_str();
	mysql_query(conn, q);
	res_set = mysql_store_result(conn);
	if ((row = mysql_fetch_row(res_set)) != NULL)
	{
		do
		{
			cout << "Employees Details of Emp no." << ++i << endl;
			cout << "Name : " << row[1] << endl;
			cout << "Address : " << endl << row[2] << endl << row[3] << endl << row[4] << endl;
			cout << "State : " << row[5] << endl;
			cout << "Contact no. : " << row[6] << endl;
			cout << "Date of Joining" << row[7] << endl;
			cout << "Salary : " << row[8] << endl;
			cout << endl << endl << endl << endl;
		} while ((row = mysql_fetch_row(res_set)) != NULL);
	}
	else
	{
		cout << "Employees Not found!" << endl;
	}
}

void Employees::update_sal()
{
	cout << "Enter the id to update the salary of an employee : ";
	int id;
	cin >> id;
	this->setId(id);
	cout << "Enter the updated salary : ";
	cin >> salary;
	stmt.str("");
	stmt << "Update employees set salary = " << salary << " where id  = " << id << ";";
	query = stmt.str();
	q = query.c_str();
	mysql_query(conn, q);
	cout << endl << endl << endl << endl;
	cout << "Salary update Successfully";
	cout << endl << endl << endl << endl;
}
