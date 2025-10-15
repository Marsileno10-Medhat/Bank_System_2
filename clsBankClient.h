#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "clsString.h"
#include "clsPerson.h"
#include "clsInputValidate.h"
using namespace std;

class clsBankClient : public clsPerson {
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

    static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#") {
        string DataLine = Client.GetFirstName() + Seperator;
        DataLine += Client.GetLastName() + Seperator;
        DataLine += Client.GetEmail() + Seperator;
        DataLine += Client.GetPhone() + Seperator;
        DataLine += Client.GetAccountNumber() + Seperator;
        DataLine += Client.GetPINcode() + Seperator;
        DataLine += Client.GetAccountBalance();
        return DataLine;
    }

    static void _SaveClientsDataToFile(vector<clsBankClient> vClients, string Seperator = "#//#") {
        fstream ClientsDataFile("Clients.txt", ios::out);
        string DataLine;
        if (ClientsDataFile.is_open()) {
            for (clsBankClient C : vClients) {
                DataLine = _ConvertClientObjectToLine(C);
                ClientsDataFile << DataLine << endl;
            }
            ClientsDataFile.close();
        }
    }

    static vector<clsBankClient> _LoadClientDataFromFile() {
        vector<clsBankClient> vClient;
        fstream ClientsDataFile ("Clients.txt", ios::out);
        if (ClientsDataFile.is_open()) {
            string DataLine = "";
            while (getline(ClientsDataFile, DataLine)) {
                clsBankClient Client = _ConvertLineToClientObject(DataLine);
                vClient.push_back(Client);
            }
            ClientsDataFile.close();
        }
        return vClient;
    }

    void _Update() {
        vector<clsBankClient> ClientsData;
        ClientsData = _LoadClientDataFromFile();
        for (clsBankClient& C : ClientsData) {
            if (C.GetAccountNumber() == _AccountNumber) {
                C = *this;
                break;
            }
        }
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

    enum enSaveResults {svFailedEmptyObject = 0, svSucceeded = 1};

    enSaveResults Save() {
        switch (_Mode) {
            case enMode::UpdateMode:
                return enSaveResults::svSucceeded;
            case enMode::EmptyMode:
                return enSaveResults::svFailedEmptyObject;
        }

    }

    static bool IsClientExist(string AccountNumber) {
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        return (!Client.IsEmpty());
    }


};