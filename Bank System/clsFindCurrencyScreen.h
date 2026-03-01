#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsString.h"

class clsFindCurrencyScreen : protected clsScreen
{
	enum _eFindBy {eCode = 1, eCountry = 2};

	static short _ReadUserOption()
	{
		cout << "\n\t\t\t\t\tFind By: ";
		return clsInputValidate::ReadShortNumberBetween(1, 2, "\t\t\t\t\tPlease Choose [1] or [2]:");

	}

	static void _PrintCurrencyCard(clsCurrency Currency)
	{
		cout << "\n\t\t\t\t\tCurrency Card:\n";
		cout << "\t\t\t\t\t_____________________________\n";
		cout << "\n\t\t\t\t\tCountry    : " << Currency.Country();
		cout << "\n\t\t\t\t\tCode       : " << Currency.CurrencyCode();
		cout << "\n\t\t\t\t\tName       : " << Currency.CurrencyName();
		cout << "\n\t\t\t\t\tRate(1$) = : " << Currency.Rate();

		cout << "\n\t\t\t\t\t_____________________________\n";
	}

	static void _FindCrrencyByCode()
	{ 
		string CurrencyCode = clsInputValidate::ReadString("\n\t\t\t\t\tPlease Enter Currency Code: ");

		if (clsCurrency::IsCurrencyExistByCode(CurrencyCode))
		{
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			cout << "\n\t\t\t\t\tCurrency Found :-)\n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\n\t\t\t\t\tCurrency NOT found :-(";
		}
	}

	static void _FindCrrencyByCountry()
	{
		string Country = clsInputValidate::ReadString("\n\t\t\t\t\tPlease Enter Currency Country: ");

		if ((clsCurrency::IsCurrencyExistByCountry(Country)))
		{
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			cout << "\n\t\t\t\t\tCurrency Found :-)\n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\n\t\t\t\t\tCurrency NOT found :-(";
		}

		
	}

	static void _PerformeUserOption(_eFindBy Option)
	{
		switch (Option)
		{
		case _eFindBy::eCode:
			_FindCrrencyByCode();
			break;

		case _eFindBy::eCountry:
			_FindCrrencyByCountry();
			break;
		}
	}

	static void _FindCurrency()
	{
		cout << setw(37) << left << "" << "\t[1] Code.\n";
		cout << setw(37) << left << "" << "\t[2] Country.\n";

		_PerformeUserOption((_eFindBy)_ReadUserOption());
	}

public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t Find Currency Screen");
		_FindCurrency();

	}
};

