#pragma once

#include <iostream>
using namespace std;

class clsScreen {

protected:
    static void _PrineScreenHeader(string Title, string SubTitle = "") {
        cout << "_______________________________________________________";
        cout << "\n\n\t\t" << Title;
        if (SubTitle != "") {
            cout << "\n\t\t" << SubTitle;
        }
        cout << "\n_______________________________________________________\n\n";
    }
};