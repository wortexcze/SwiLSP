#pragma once
#include <iostream>
#include "Settings.h"

using std::string;

class Person
{
protected:
    int id;
    string name;
    string addr_line1;
    string addr_line2;
    string addr_city;
    string addr_state;
    long int phn;

public:
    virtual int getId() const;
   virtual string getName() const;
   virtual string getAddrLine1() const;
   virtual string getAddrLine2() const;
   virtual string getAddrCity() const;
   virtual string getAddrState() const;
   virtual long int getPhn() const;

    // Setters
   virtual void setId(int i);
   virtual void setName(const string& newName);
   virtual void setAddrLine1(const string& newAddrLine1);
   virtual void setAddrLine2(const string& newAddrLine2);
   virtual void setAddrCity(const string& newAddrCity);
   virtual void setAddrState(const string& newAddrState);
   virtual void setPhn(long int newPhn);

    Person() {}
    Person(const string& newName, const string& newAddrLine1, const string& newAddrLine2,
        const string& newAddrCity, const string& newAddrState, long int newPhn)
        : name(newName), addr_line1(newAddrLine1), addr_line2(newAddrLine2),
        addr_city(newAddrCity), addr_state(newAddrState), phn(newPhn) {}

    virtual ~Person() {};
};


