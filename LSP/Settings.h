#pragma once
#include <iostream>
#include <mysql/mysql.h>
using std::string;
using std::stringstream;

MYSQL* conn;
MYSQL_RES* res_set;
MYSQL_ROW row;
stringstream stmt;
const char* q;
string query;
// my_bool result;

#define HOST "127.0.0.1"
#define USER "root"
#define PASS 
#define DATABASE "Management"
#define PORT 3306
#define PASSWORD /*Set a Numeric Password for Your Application*/