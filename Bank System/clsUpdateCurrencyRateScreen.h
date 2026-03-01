#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"
#include "clsString.h"

class clsUpdateCurrencyRateScreen : protected clsScreen
{
	static clsCurrency _ReadCurrency(string Message)
	{
		string CurrencyCode = clsInputValidate::ReadString(Message);

		while (!(clsCurrency::IsCurrencyExistByCode(CurrencyCode)))
		{
			CurrencyCode = clsInputValidate::ReadString("\n\t\t\t\t\tCurrency Code NOT Found, Enter Another Code: ");
		}

		return clsCurrency::FindByCode(CurrencyCode);
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

	static void _UpdateCurrencyRate()
	{
		clsCurrency Currency = _ReadCurrency("\n\t\t\t\t\tPlease enter currency Code: ");
		_PrintCurrencyCard(Currency);

		char Answer = clsInputValidate::ReadChar("\n\t\t\t\t\tAre you sure you want to update rate of this currency? y/n? ");
		
		if (tolower(Answer) == 'y')
		{

			cout << "\n\t\t\t\t\tUpdate Currency Rate:\n";
			cout << "\n\t\t\t\t\t-------------------------\n";
			cout << "\n\t\t\t\t\tEnter New Rate: ";
			float NewRate = clsInputValidate::ReadFloatNumber();
			Currency.UpdateRate(NewRate);
			cout << "\n\t\t\t\t\tCurrency Rate Update Successfullt :-)\n";
			_PrintCurrencyCard(Currency);
		}
		else
		{
			cout << "\n\t\t\t\t\tOperation Concled";
		}
		
	}

public:

	static void ShowUpdateCurrencyRate()
	{
		_DrawScreenHeader("\t Update Currency Screen");

		_UpdateCurrencyRate();
	}
};

