#include <iostream>
#include <windows.h>
#include <mysql/mysql.h>
#include <sstream>
#include <conio.h>

#include "Settings.h"
#include "Date.h"
#include "Books.h"
#include "Suppliers.h"
#include "Employees.h"
#include "Purchases.h"
#include "Sales.h"
#include "Members.h"
#include "Functions.h"



using namespace std;





int main()
{
	/*
	pass();
	conn = mysql_init(0);
	conn = mysql_real_connect(conn, HOST, USER, PASS, DATABASE, PORT, NULL, 0);
	int choice;
	if (conn)
	{
		while (1)
		{
			system("cls");
			main_menu();
		}
	}
	else
	{
		system("cls");
		cout << "Error While connection to database." << endl << "Contact Tech Expert." << endl;
		getch();
	}

	*/

	Person* p = new Person("jakub", "adr1", "adr2", "city", "state", 12000);
	Person* m = new Members();
	Person* e = new Employees();
	
	m->add_mem(); //přidání iformací do třidy members
	e->add_emp(); //přidání iformací do třidy employes

	display(*m); //tohle se zobrazí v pořadku
	display(*e); //tohle se zobrazí v pořadku
	display(*p); //tady nastane chyba protože podle LSP má být bázová třída Person volně zastupitelná
	return 0;
}
