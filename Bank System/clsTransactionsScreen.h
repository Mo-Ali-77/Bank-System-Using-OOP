#pragma once
#include"clsScreen.h"
#include"clsMainScreen.h"
#include"clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"

class clsTransactionsScreen : protected clsScreen
{
    enum _eTransactionsMenue {  eDeposit = 1, eWithdraw = 2, eCheckBalance = 3, eTransfer = 4, eBackToMainMenue = 5 };

    static short _ReadMainMenueOptions()
    {
        cout << setw(37) << left << "" << "Chooce what do you want do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "\n\t\t\t\t     Enter Number Between 1 to 5? ");
        return Choice;
    }

    static void _GoBackToTransactionsMenue()
    {
        cout << "\n\n\t\t\t\t\tPress any key to go back to Transactions Menue...";
        system("pause>0");
        clsScreen::_ResetScreen();
        ShowTransactionsMenue();
    }

    static void _ShowDepositScreen()
    {
        clsDepositScreen::ShowDepositScreen();
    }

    static void _ShowWithdrawScreen()
    {
        clsWithdrawScreen::ShowWithdrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalances();
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _PerfromeTransactionsMenueOptions(_eTransactionsMenue TransactionsMenueOption)
    {
        switch (TransactionsMenueOption)
        {
        case _eTransactionsMenue::eDeposit:

            clsScreen::_ResetScreen();
            
            _ShowDepositScreen();
            _GoBackToTransactionsMenue();
            break;

        case _eTransactionsMenue::eWithdraw:

            clsScreen::_ResetScreen();
            _ShowWithdrawScreen();
           
            _GoBackToTransactionsMenue();

            break;

        case _eTransactionsMenue::eCheckBalance:

            clsScreen::_ResetScreen();
           
            _ShowTotalBalancesScreen();
            _GoBackToTransactionsMenue();

            break;

        case _eTransactionsMenue::eTransfer:

            clsScreen::_ResetScreen();
            _ShowTransferScreen();
            _GoBackToTransactionsMenue();
            break;

        case _eTransactionsMenue::eBackToMainMenue:

            // do nothing here the main will handle it :-)
            
            break;
        }
    }

	static void _TransactionsMenue()
	{
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Back to Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromeTransactionsMenueOptions((_eTransactionsMenue)_ReadMainMenueOptions());
	}

public : 

	static void ShowTransactionsMenue()
	{
        if (!(_CheckAccessRights(clsUser::enPermissions::pTransactions)))
            return;

        _DrawScreenHeader("\tTransactions Menue");
        _TransactionsMenue();

	}
};

