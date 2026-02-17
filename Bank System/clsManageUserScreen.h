#pragma once
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"

class clsManageUserScreen : protected clsScreen
{
    enum _enManageUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5, eMainMenue = 6
    };

    static short _ReadManageUserOption()
    {
        cout << setw(37) << left << "" << "Chooce what do you want do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "\n\t\t\t\t     Enter Number Between 1 to 6? ");
        return Choice;
    }

    static void _GoBackToManageUsersMenue()
    {
        cout << "\n\n\t\t\t\t\tPress any key to go back to Manage Users Menue...";
        system("pause>0");
        ShowManageUsersMenue();
    }


    static void _ShowListUsersScreen()
    {
        clsListUsersScreen::ShowUsersList();

    }

    static void _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUser();

    }

    static void _ShowDeleteUserScreen()
    {
        clsDeleteUserScreen::ShowDeleteUserScreen();

    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }

    
    static void _PerfromeManageUserMenueOptions(_enManageUsersMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case _enManageUsersMenueOptions::eListUsers:

            clsScreen::_ResetScreen();
            _ShowListUsersScreen();
            _GoBackToManageUsersMenue();
            break;

        case _enManageUsersMenueOptions::eAddNewUser:

            clsScreen::_ResetScreen();
            _ShowAddNewUserScreen();
            _GoBackToManageUsersMenue();
            break;

        case _enManageUsersMenueOptions::eDeleteUser:

            clsScreen::_ResetScreen();
            _ShowDeleteUserScreen();
            _GoBackToManageUsersMenue();
            break;

        case _enManageUsersMenueOptions::eUpdateUser:

            clsScreen::_ResetScreen();
            _ShowUpdateUserScreen();
            _GoBackToManageUsersMenue();
            break;

        case _enManageUsersMenueOptions::eFindUser:

            clsScreen::_ResetScreen();
            _ShowFindUserScreen();
            _GoBackToManageUsersMenue();
            break;

        case _enManageUsersMenueOptions::eMainMenue:


            break;
        }
    }

public:

	static void ShowManageUsersMenue()
	{
        if (!(_CheckAccessRights(clsUser::enPermissions::pManageUsers)))
            return;

		_DrawScreenHeader("\tManage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromeManageUserMenueOptions((_enManageUsersMenueOptions)_ReadManageUserOption());

	}
};

