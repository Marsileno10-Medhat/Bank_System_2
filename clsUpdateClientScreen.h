#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsUpdateClientScreen : protected clsScreen {

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

    static void UpdateClient() {

        clsScreen::_PrineScreenHeader("Update client data");
        string AccountNumber = clsInputValidate::ReadString("\nEnter the account number: ");
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            AccountNumber = clsInputValidate::ReadString("\nAccount number is not found. Enter the account number: ");
        }
        clsBankClient Client = clsBankClient::Find(AccountNumber);
        _PrintClientCard(Client);

        char ConfirmModification = 'N';
        ConfirmModification = clsInputValidate::ReadChar("\n\nAre you sure you woulke to modify this client? [Y:N]. ");

        if (toupper(ConfirmModification) == 'Y') {

            cout << "\nUpdate the account details:\n";
            cout << "-------------------------------" << endl;
            _ReadClientData(Client);
            clsBankClient::enSaveResults SaveResaults = Client.Save();

            switch (SaveResaults) {
                case clsBankClient::enSaveResults::svSucceeded:
                    cout << "\nAccount data has been successfully updated.\n";
                    _PrintClientCard(Client);
                    break;
                case clsBankClient::enSaveResults::svFailedEmptyObject:
                    cout << "\nError account was not saved because it's Empty";
                    break;
            }
        }
    }
};