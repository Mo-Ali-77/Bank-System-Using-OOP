#pragma once
#include <iostream>
#include "clsUser.h"
#include "Gloabl.h"
#include "clsDate.h"
using namespace std;

class clsScreen
{
protected:

    static void _ResetScreen()
    {
        system("cls");
    }

	static void _DrawScreenHeader(string HeaderTitle, string SubTitle = "")
	{
        _ResetScreen();
        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t  " << HeaderTitle;

        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }

        cout << "\n\t\t\t\t\t______________________________________\n\n";

        cout << "\t\t\t\t\tUserName: " << CurrentUser.UserName << endl;
        cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate::GetSystemDate()) << endl << endl;
	}

    static bool _CheckAccessRights(clsUser::enPermissions Permission)
    {
        if (!CurrentUser.CheckAccessPermission(Permission))
        {
            cout << "\t\t\t\t\t______________________________________";
            cout << "\n\n\t\t\t\t\t  Access Denied! Contact your Admin.";
            cout << "\n\t\t\t\t\t______________________________________\n\n";
            return false;
        }
        else
        {
            return true;
        }

    }
};

