#pragma once

#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
using namespace std;

class clsMainScreen : protected clsScreen {

private:
    enum enMainMenuOptions {eClientList = 1, eAddClient = 2, eDeleteClient = 3, eUpdatedClient = 4, eFindClient = 5, eTransactions = 6, eManageUsers = 7, eLogout = 8};

    static short _ReadMainMenuOption() {
        short Choice = clsInputValidate::ReadNumberInRange(1, 8, "Choose what do you want to do? [1 to 8]? ", "Invalid input, Choose what do you want to do? [1 to 8]? ");
        return Choice;
    }

    static void _BackToMainMenuScreen() {
        cout << "\nPress any key to go back to Main Menue...\n";
        system("pause>0");
        ShowMainMenuScreen();
    }

    static void _ShowClientListScreen() {
        cout << "\nClient list screen will be here soon...\n";
    }
    
    static void _ShowAddClientScreen() {
        cout << "\nAdd client screen will be here soon...\n";
    }

    static void _ShowDeleteClientScreen() {
        cout << "\nDelete client screen will be here soon...\n";
    }

    static void _ShowUpdateClientScreen() {
        cout << "\nUpdate client screen will be here soon...\n";
    }

    static void _ShowFindClientScreen() {
        cout << "\nFind client screen will be here soon...\n";
    }

    static void _ShowTransactionScreen() {
        cout << "\nTransaction screen will be here soon...\n";
    }

    static void _ShowManageUsersScreen() {
        cout << "\nManage users screen will be here soon...\n";
    }

    static void _ShowEndScreen() {
        cout << "\nEnd screen will be here soon...\n";
    }

    static void PerforMainMenuOption(clsMainScreen::enMainMenuOptions MainMenuChoice) {
        switch(MainMenuChoice) {
            case clsMainScreen::enMainMenuOptions::eClientList:
                system("cls");
                _ShowClientListScreen();
                _BackToMainMenuScreen();
                break;
            case clsMainScreen::enMainMenuOptions::eAddClient:
                system("cls");
                _ShowAddClientScreen();
                _BackToMainMenuScreen();
                break;
            case clsMainScreen::enMainMenuOptions::eDeleteClient:
                system("cls");
                _ShowDeleteClientScreen();
                _BackToMainMenuScreen();
                break;
            case clsMainScreen::enMainMenuOptions::eUpdatedClient:
                system("cls");
                _ShowUpdateClientScreen();
                _BackToMainMenuScreen();
                break;
            case clsMainScreen::enMainMenuOptions::eFindClient:
                system("cls");
                _ShowFindClientScreen();
                _BackToMainMenuScreen();
                break;
            case clsMainScreen::enMainMenuOptions::eTransactions:
                system("cls");
                _ShowTransactionScreen();
                _BackToMainMenuScreen();
                break;
            case clsMainScreen::enMainMenuOptions::eManageUsers:
                system("cls");
                _ShowManageUsersScreen();
                _BackToMainMenuScreen();
                break;
            case clsMainScreen::enMainMenuOptions::eLogout:
                system("cls");
                _ShowEndScreen();
                _BackToMainMenuScreen();
                break;
        }
    }

public:
    static void ShowMainMenuScreen() {
        system("cls");
        clsScreen::_PrineScreenHeader("MainScreen");
        cout << "\n========================================\n";
        cout << "\n\t\tMain Menu\n";
        cout << "\n========================================\n";
        cout << " [1] Show clients list.\n";
        cout << " [2] Add new client.\n";
        cout << " [3] Delete client.\n";
        cout << " [4] Update client.\n";
        cout << " [5] Find client.\n";
        cout << " [6] Transactions.\n";
        cout << " [7] Manage users.\n";
        cout << " [8] Logout.\n";
        cout << "========================================\n";
        PerforMainMenuOption((clsMainScreen::enMainMenuOptions)_ReadMainMenuOption());
    }
};