#pragma once
#include <iostream>
#include "clsScreen.h"
#include <iomanip>
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include "clsClientListScreen.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include "clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include "clsTransactionsScreen.h"
#include "clsManageUserScreen.h"
#include "Gloabl.h"
#include "clsLoginScreen.h"
#include "clsLoginRegisterScreen.h"
#include "clsCurrencyExchangeScreen.h"

using namespace std;

class clsMainScreen : protected clsScreen
{
    enum _enMainMenueOptions {
        eListClients = 1, eAddNewClient = 2, eDeleteClient = 3,
        eUpdateClient = 4, eFindClient = 5, eShowTransactionsMenue = 6,
        eManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eExit = 10
    };

    static short _ReadMainMenueOptions()
    {
        cout << setw(37) << left << "" << "Chooce what do you want do? [1 to 10]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 10, "\n\t\t\t\t     Enter Number Between 1 to 10? ");
        return Choice;
    }

    static void _GoBackToMainMenue()
    {
        cout << "\n\n\t\t\t\t\tPress any key to go back to Main Menue...";
        system("pause>0");
        clsScreen::_ResetScreen();
        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {

        clsClientListScreen::ShowClientList();
        
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientsScreen();
    }

    static void _ShowDeleteClientScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowFindClientScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionsScreen::ShowTransactionsMenue();

    }

    static void _ShowManageUsersMenue()
    {
        clsManageUserScreen::ShowManageUsersMenue();
    }

    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _ShowCurrencyExchangeScreen()
    {
        clsCurrencyExchangeScreen::ShowCurrencyExchangeScreen();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");

        // Circle Refernce, Not allowed to call this Function here.
        // clsLoginScreen::ShowLoginScreen();
    }

    static void _PerfromeMainMenueOptions(_enMainMenueOptions MainMenueOption)
    {
        switch (MainMenueOption)
        {
        case _enMainMenueOptions::eListClients:

            clsScreen::_ResetScreen();
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;

        case _enMainMenueOptions::eAddNewClient:

            clsScreen::_ResetScreen();
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;

        case _enMainMenueOptions::eDeleteClient:

            clsScreen::_ResetScreen();
            _ShowDeleteClientScreen();
            _GoBackToMainMenue();
            break;
        
        case _enMainMenueOptions::eUpdateClient:
        
            clsScreen::_ResetScreen();
            _ShowUpdateClientScreen();
            _GoBackToMainMenue();
            break;
       
        case _enMainMenueOptions::eFindClient:
            
            clsScreen::_ResetScreen();
            _ShowFindClientScreen();
            _GoBackToMainMenue();
            break;
        
        case _enMainMenueOptions::eShowTransactionsMenue:
        
            clsScreen::_ResetScreen();
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;
        
        case _enMainMenueOptions::eManageUsers:
        
            clsScreen::_ResetScreen();
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;
        
        case _enMainMenueOptions::eLoginRegister:

            clsScreen::_ResetScreen();
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;
        case _enMainMenueOptions::eCurrencyExchange:

            clsScreen::_ResetScreen();
            _ShowCurrencyExchangeScreen();
            _GoBackToMainMenue();
            break;

        case _enMainMenueOptions::eExit:

            clsScreen::_ResetScreen();
            _Logout();
            
            break;
        }
    }

public:

	static void ShowMainMenue()
	{
		_DrawScreenHeader("\t     Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
        cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
        cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
        cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find Client.\n";
        cout << setw(37) << left << "" << "\t[6] Transactions.\n";
        cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
        cout << setw(37) << left << "" << "\t[8] Login Register List.\n";
        cout << setw(37) << left << "" << "\t[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "\t[10] Logout.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromeMainMenueOptions((_enMainMenueOptions)_ReadMainMenueOptions());

	}

};

