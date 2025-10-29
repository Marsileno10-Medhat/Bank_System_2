#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsDeleteClientScreen : protected clsScreen {

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

public:

    static void DeleteClient() {

        clsScreen::_PrineScreenHeader("Delete client");
        string AccountNumber = clsInputValidate::ReadString("\nEnter the account number: ");
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            AccountNumber = clsInputValidate::ReadString("\nAccount number is not found. Enter the account number: ");
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClientCard(Client);

        char ConfirmDelete = clsInputValidate::ReadChar("\nAre you sure you want to delete this client y/n? ");
        if (toupper(ConfirmDelete) == 'Y') {
            if (Client.Delete()) {
                cout << "\nClient Deleted Successfully.\n";
            }
            else {
                cout << "\nError Client Was not Deleted\n";
            }
        }
    }
};