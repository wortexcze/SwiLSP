#include "Functions.h"


void display(Person& a) {
	cout << a.getId() << endl;
	cout << a.getName() << " " << a.getAddrCity() << " \n" << a.getAddrLine1() << " " << a.getAddrLine2() << "\n" << a.getAddrState() << endl;
	cout << a.getPhn() << endl;
}

void main_menu()
{
	int c;
	cout << "   1. BOOKS" << endl;
	cout << "   2. SUPPLIERS" << endl;
	cout << "   3. PURCHASES" << endl;
	cout << "   4. EMPLOYEES" << endl;
	cout << "   5. MEMBERS" << endl;
	cout << "   6. SALES" << endl;
	cout << "   7. EXIT" << endl << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
	case 1:
		system("cls");
		book_menu();
		getch();
		break;
	case 2:
		system("cls");
		sup_menu();
		getch();
		break;
	case 3:
		system("cls");
		pur_menu();
		getch();
		break;
	case 4:
		system("cls");
		emp_menu();
		getch();
		break;
	case 5:
		system("cls");
		mem_menu();
		getch();
		break;
	case 6:
		system("cls");
		sal_menu();
		getch();
		break;
	case 7:
		exit(1);
	default:
		system("cls");
		cout << "Wrong Input" << endl << endl << "Invalid input";
		getch();
		break;
	}
	return;
}

// book menu

void book_menu()
{
	int c;
	Books b;
	cout << "   1. ADD" << endl;
	cout << "   2. UPDATE PRICE" << endl;
	cout << "   3. SEARCH" << endl;
	cout << "   4. UPDATE STATUS" << endl;
	cout << "   5. DISPLAY ALL" << endl;
	cout << "   6. RETURN TO MAIN MENU" << endl << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
	case 1:
		b.add();
		break;
	case 2:
		b.update_price();
		break;
	case 3:
		b.search();
		break;
	case 4:
		b.update();
		break;
	case 5:
		b.display();
		break;
	case 6:
		return;
		break;
	default:
		cout << "Wrong Input" << endl << "Invalid input";
		break;
	}
	return;
}

// supp menu

void sup_menu()
{
	int c;
	Suppliers s;
	cout << "   1. ADD" << endl;
	cout << "   2. REMOVE" << endl;
	cout << "   3. SEARCH" << endl;
	cout << "   4. RETURN TO MAIN MENU" << endl << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
	case 1:
		s.add_sup();
		break;
	case 2:
		s.remove_supplier();
		break;
	case 3:
		s.search_id();
		break;
	case 4:
		return;
	default:
		cout << "Wrong Input" << endl << "Invalid input";
		break;
	}
}

// purchase menu

void pur_menu()
{
	int c;
	Purchases p;
	cout << "   1. New Order" << endl;
	cout << "   2. View All" << endl;
	cout << "   3. Cancel Order" << endl;
	cout << "   4. Recieved Order" << endl;
	cout << "   5. RETURN TO MAIN MENU" << endl << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
	case 1:
		p.new_ord();
		break;
	case 2:
		p.view();
		break;
	case 3:
		p.mar_cancel();
		break;
	case 4:
		p.mark_reciv();
		break;
	case 5:
		return;
	default:
		cout << "Wrong Input" << endl << "Invalid input";
		break;
	}
}

// emp_menu

void emp_menu()
{
	int c;
	Employees e;
	cout << "   1. New Employee" << endl;
	cout << "   2. Search Employee" << endl;
	cout << "   3. Assign Manager" << endl;
	cout << "   4. View All" << endl;
	cout << "   5. Update Salary" << endl;
	cout << "   6. RETURN TO MAIN MENU" << endl << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
	case 1:
		e.add_emp();
		break;
	case 2:
		e.search_emp();
		break;
	case 3:
		e.assign_mgr_stat();
		break;
	case 4:
		e.display();
		break;
	case 5:
		e.update_sal();
		break;
	case 6:
		return;
	default:
		cout << "Wrong Input" << endl << "Invalid input";
		break;
	}
}


// mem menu

void mem_menu()
{
	int c;
	Members m;
	m.refresh();
	cout << "   1. New Member" << endl;
	cout << "   2. Search Member" << endl;
	cout << "   3. RETURN TO MAIN MENU" << endl << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
	case 1:
		m.add_mem();
		break;
	case 2:
		m.search_mem();
		break;
	case 3:
		return;
	default:
		cout << "Wrong Input" << endl << "Invalid input";
		break;
	}
}

// sal_menu

void sal_menu()
{
	int c;
	Sales s;
	cout << "   1. Add New Bill" << endl;
	cout << "   2. Total Sales Of The Year" << endl;
	cout << "   3. RETURN TO MAIN MENU" << endl << endl << endl;
	cout << "Enter Your Choice : ";
	cin >> c;
	switch (c)
	{
	case 1:
		s.add();
		break;
	case 2:
		s.find_total_sales();
		break;
	case 3:
		return;
	default:
		cout << "Wrong Input" << endl << "Invalid input";
		break;
	}
}


// Password Function

void pass()
{
	int num = 0;
	cout << "Enter password : ";
	for (int i = 0; i < 4; i++)
	{
		num = num * 10 + (getch() - 48);
		cout << "*";
	}
	if (num == PASSWORD)
	{
		cout << endl << endl << "Correct Password" << endl << endl;
		cout << "Press any key...";
		getch();
	}
	else
	{
		cout << endl << endl << "Incorrect Password" << endl << endl;
		cout << "Press any key...";
		getch();
		exit(1);
	}
	return;
}

