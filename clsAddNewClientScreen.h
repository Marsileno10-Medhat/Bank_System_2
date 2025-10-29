#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
using namespace std;

class clsAddNewClientScreen : protected clsScreen {

private:

    static void _PrintClientCard(clsBankClient Client) {
        cout << "\n---------------------------------------------------";
        cout << "\n\t\tClient data:";
        cout << "\n---------------------------------------------------";
        cout << "\n- First name       : " << Client.GetFirstName();
        cout << "\n- Last name        : " << Client.GetLastName();
        cout << "\n- Full name        : " << Client.GetFullName();
        cout << "\n- Phone number     : " << Client.GetPhone();
        cout << "\n- Email address    : " << Client.GetEmail();
        cout << "\n- Account number   : " << Client.GetAccountNumber();
        cout << "\n- PIN code         : " << Client.GetPINcode();
        cout << "\n- Account balance  : " << Client.GetAccountBalance();
        cout << "\n---------------------------------------------------";
    }
    static void _ReadClientData(clsBankClient& Client) {
        Client.SetFirstName(clsInputValidate::ReadString("\nEnter the first name: "));
        Client.SetLastName(clsInputValidate::ReadString("\nEnter the last name: "));
        Client.SetEmail(clsInputValidate::ReadString("\nEnter the email address: "));
        Client.SetPhone(clsInputValidate::ReadString("\nEnter the phone number: "));
        Client.SetPINcode(clsInputValidate::ReadString("\nEnter the PIN code: "));
        Client.SetAccountBalance(clsInputValidate::ReadValidNumber<float>("\nEnter the balance: ", "/nInvalid number, Enter the balance: "));
    }

public:

    static void AddNewClient() {
        clsScreen::_PrineScreenHeader("Add new client");
        string AccountNumber = clsInputValidate::ReadString("\nEnter the new account number: ");
        while (clsBankClient::IsClientExist(AccountNumber)) {
            AccountNumber = clsInputValidate::ReadString("\nAccount number is used. Enter the new account number: ");
        }
        clsBankClient NewClient = clsBankClient::GetAddClientObject(AccountNumber);
        _ReadClientData(NewClient);

        clsBankClient::enSaveResults SaveResult = NewClient.Save();

        switch(SaveResult) {
            case clsBankClient::enSaveResults::svSucceeded:
                cout << "\nAccount added successfully.\n";
                _PrintClientCard(NewClient);
                break;
            case clsBankClient::enSaveResults::svFailedEmptyObject:
                cout << "\nFaild to save the client data because it's empty.\n";
                break;
            case clsBankClient::enSaveResults::svFaliedAccountNumberExists:
                cout << "\nFailed to save the client data because the account number already used.\n";
        }
    }

};