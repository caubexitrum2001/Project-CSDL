#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Account 
{
    string _strUser;
    string _strPin;
public:
    Account()
    {
        _strUser = _strPin = "Unknown!";
    }
    Account(string sU, string sP)
    {
        _strUser = sU;
            _strPin = sP;
    }
    friend ifstream& operator >> (ifstream& is, Account& a);

    bool operator == (const Account& a);

    void setUser();
    string getUser();

    string getPin();
    void setPin(string pin);
};

