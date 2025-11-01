#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
using namespace std;

class clsTransactionsScreen : protected clsScreen {

private:
    enum enTransactionsMenuOptions {eDeposit = 1, eWithdraw = 2, eTotalBalance = 3, eMainMenu = 4};

    static short _ReadTransactionsMenuOption() {
        short Choice = clsInputValidate::ReadNumberInRange(1, 4, "Choose what do you want to do? [1:4]. ", "Invalid input, Choose what do you want to do? [1:4]. ");
        return Choice;
    }

    static void _BackToTransactionsMenuScreen() {
        cout << "\nPress any key to go back to transactions Menu...\n";
        system("pause>0");
        ShowTransactionMenuScreen();
    }

    static void _ShowDepositScreen() {
        cout << "\nDeposit screen will be here soon...\n";
    }

    static void _ShowWithdrawScreen() {
        cout << "\nWithdraw screen will be here soon...\n";
    }

    static void _ShowTotalBalanceScreen() {
        cout << "\nTotal balance screen will be here soon...\n";
    }

    static void _PerforTransactionsMenuOption(clsTransactionsScreen::enTransactionsMenuOptions TransactionMenuChoice) {
        switch (TransactionMenuChoice) {
            case clsTransactionsScreen::enTransactionsMenuOptions::eDeposit:
                system("cls");
                _ShowDepositScreen();
                _BackToTransactionsMenuScreen();
                break;
            case clsTransactionsScreen::enTransactionsMenuOptions::eWithdraw:
                system("cls");
                _ShowWithdrawScreen();
                _BackToTransactionsMenuScreen();
                break;
            case clsTransactionsScreen::enTransactionsMenuOptions::eTotalBalance:
                system("cls");
                _ShowTotalBalanceScreen();
                _BackToTransactionsMenuScreen();
                break;
            case clsTransactionsScreen::enTransactionsMenuOptions::eMainMenu:
                break;
        }
    }
public:

    static void ShowTransactionMenuScreen() {
        system("cls");
        clsScreen::_PrineScreenHeader("Transactions menu");
        cout << "\n========================================\n";
        cout << "\n\tTransactions Menu\n";
        cout << "\n========================================\n";
        cout << " [1] Deposit.\n";
        cout << " [2] Withdraw.\n";
        cout << " [3] Total balance.\n";
        cout << " [4] Main menu.\n";
        cout << "========================================\n";
        _PerforTransactionsMenuOption((clsTransactionsScreen::enTransactionsMenuOptions)_ReadTransactionsMenuOption());
    }
};