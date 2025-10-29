#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindClientScreen : protected clsScreen {

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

    static void FindClient() {
        clsScreen::_PrineScreenHeader("Find client");
        string AccountNumber = clsInputValidate::ReadString("Enter the account number: ");  
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        if (Client.IsClientExist(Client.GetAccountNumber())) {
            _PrintClientCard(Client);
        }
        else {
            cout << "\nClient is not found.\n";
        }
    }

};