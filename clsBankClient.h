#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "clsString.h"
#include "clsPerson.h"
using namespace std;

class clsBankClient : private clsPerson {
private:
    enum enMode {EmptyMode = 0, UpdateMode = 1};
    enMode _Mode;

    string _AccountNumber;
    string _PINcode;
    double _AccountBalance;

    static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#") {
        vector<string> vClientData = clsString::Split(Line, Seperator);
        return clsBankClient(vClientData[0], vClientData[1], vClientData[2], vClientData[3], vClientData[4], vClientData[5], stod(vClientData[6]));  
    }

    static clsBankClient _GetEmptyClientData() {
        return clsBankClient("", "", "", "", "", "", 0);
    }

    bool IsEmpty() {
        return (_Mode == enMode::EmptyMode);
    }

public:
    clsBankClient(string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PINcode, double AccountBalance) : clsPerson(FirstName, LastName, Email, Phone) {
        _AccountNumber = AccountNumber;
        _PINcode = PINcode;
        _AccountBalance = AccountBalance;
    }

    string GetAccountNumber() {
        return _AccountNumber;
    }

    void SetPINcode(string PINcode) {
        _PINcode = PINcode;
    }

    string GetPINcode() {
        return _PINcode;
    }

    void SetAccountBalance(double AccountBalance) {
        _AccountBalance = AccountBalance;
    }

    double GetAccountBalance() {
        return _AccountBalance;
    }

    static clsBankClient Find(string AccountNumber) {

        fstream ClientsDataFile("Clients.txt", ios::in);
        if (ClientsDataFile.is_open()) {
            string Line = "";

            while (getline(ClientsDataFile, Line)) {
                clsBankClient Client = _ConvertLineToClientObject(Line);

                if (AccountNumber == Client.GetAccountNumber()) {
                    ClientsDataFile.close();
                    return Client;
                }
            }
            ClientsDataFile.close();
        }
        return _GetEmptyClientData();
    }

    static clsBankClient Find(string AccountNumber, string PINcode) {
        clsBankClient Client = Find(AccountNumber);

        if (PINcode == Client.GetPINcode()) {
            return Client;
        }
        return _GetEmptyClientData();
    }

    static IsClientExist(string AccountNumber) {
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        return (!Client.IsEmpty());
    }

    void Print() {
        cout << "\nClient data:";
        cout << "\n---------------------------------------------------";
        cout << "\n- First name       : " << GetFirstName();
        cout << "\n- Last name        : " << GetLastName();
        cout << "\n- Full name        : " << GetFullName();
        cout << "\n- Phone number     : " << GetPhone();
        cout << "\n- Email address    : " << GetEmail();
        cout << "\n- Account number   : " << _AccountNumber;
        cout << "\n- PIN code         : " << _PINcode;
        cout << "\n- Account balance  : " << _AccountBalance;
        cout << "\n---------------------------------------------------";
    }

};