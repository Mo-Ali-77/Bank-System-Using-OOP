#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"


class clsCurrencyExchangeScreen :protected clsScreen
{
    enum enCurrenyMainMenue {
        eListCurrencies = 1, eFindCurrency = 2,
        eUpdateRate = 3, eCurrencyCalculate = 4, eMainMenue = 5
    };

    static void _GoBackToCurrenyMainMenue()
    {
        cout << "\n\n\t\t\t\t\tPress any key to go back to Currency Exchang Menue...";
        system("pause>0");
        clsScreen::_ResetScreen();
        ShowCurrencyExchangeScreen();
    }

    static short _ReadMainCurrenyExchangeMenueOptions()
    {
        cout << setw(37) << left << "" << "Chooce what do you want do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "\n\t\t\t\t     Enter Number Between 1 to 5? ");
        return Choice;
    }

    static void _ShowListCurrenciesScreen()
    {
        clsListCurrenciesScreen::ShowListCurrenciesScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreen()
    {
        cout << "List Currency Screen will be here.\n";
    }

    static void _ShowCurrencyCalculateScreen()
    {
        cout << "List Currency Screen will be here.\n";
    }

    static void _PerfromeMainMenueOptions(enCurrenyMainMenue CurrenyMainMenueOption)
    {
        switch (CurrenyMainMenueOption)
        {
        case enCurrenyMainMenue::eListCurrencies:

            clsScreen::_ResetScreen();
            _ShowListCurrenciesScreen();
            _GoBackToCurrenyMainMenue();
            break;

        case enCurrenyMainMenue::eFindCurrency:

            clsScreen::_ResetScreen();
            _ShowFindCurrencyScreen();
            _GoBackToCurrenyMainMenue();
            break;

        case enCurrenyMainMenue::eUpdateRate:

            clsScreen::_ResetScreen();
            _ShowUpdateRateScreen();
            _GoBackToCurrenyMainMenue();
            break;

        case enCurrenyMainMenue::eCurrencyCalculate:

            clsScreen::_ResetScreen();
            _ShowCurrencyCalculateScreen();
            _GoBackToCurrenyMainMenue();
            break;

        case enCurrenyMainMenue::eMainMenue:

            break;
        }
    
    }

public:

	static void ShowCurrencyExchangeScreen()
	{
		_DrawScreenHeader("\t Currency Exchange Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menue.\n";
        cout << setw(37) << left << "" << "===========================================\n";
        
        _PerfromeMainMenueOptions((enCurrenyMainMenue)_ReadMainCurrenyExchangeMenueOptions());

	}
};

