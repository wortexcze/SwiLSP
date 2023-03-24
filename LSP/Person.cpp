#include "Person.h"

// Getters

 string Person::getName() const { return name; }
string Person::getAddrLine1() const { return addr_line1; }
string Person::getAddrLine2() const { return addr_line2; }
string Person::getAddrCity() const { return addr_city; }
string Person::getAddrState() const { return addr_state; }
long int Person::getPhn() const { return phn; }

// Setters
void Person::setName(const string& newName) { name = newName; }
void Person::setAddrLine1(const string& newAddrLine1) { addr_line1 = newAddrLine1; }
void Person::setAddrLine2(const string& newAddrLine2) { addr_line2 = newAddrLine2; }
void Person::setAddrCity(const string& newAddrCity) { addr_city = newAddrCity; }
void Person::setAddrState(const string& newAddrState) { addr_state = newAddrState; }
void Person::setPhn(long int newPhn) { phn = newPhn; }

