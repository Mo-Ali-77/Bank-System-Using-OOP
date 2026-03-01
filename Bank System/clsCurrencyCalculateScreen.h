#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

class clsCurrencyCalculateScreen : protected clsScreen
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

	static float _ReadAmount(string Message)
	{
		cout << Message;
		float Amount = clsInputValidate::ReadFloatNumber();
		return Amount;
	}

	static void _PrintCurrencyCard(clsCurrency Currency, string Title = "Currency Card:")
	{
		cout << "\n\t\t\t\t\t" << Title;
		cout << "\n\t\t\t\t\t_____________________________\n";
		cout << "\n\t\t\t\t\tCountry    : " << Currency.Country();
		cout << "\n\t\t\t\t\tCode       : " << Currency.CurrencyCode();
		cout << "\n\t\t\t\t\tName       : " << Currency.CurrencyName();
		cout << "\n\t\t\t\t\tRate(1$) = : " << Currency.Rate();
		cout << "\n\t\t\t\t\t_____________________________\n";
	}

	static void _CurrencyCalculate()
	{
		clsCurrency CurrencyFrom = _ReadCurrency("\n\t\t\t\t\tPlease enter currency From code: ");
		clsCurrency CurrencyTo = _ReadCurrency("\n\t\t\t\t\tPlease enter currency To code  : ");

		float Amount = _ReadAmount("\n\t\t\t\t\tPlease enter Amount: ");

		_PrintCurrencyCard(CurrencyFrom, "Convert From:");

		cout << "\n\t\t\t\t\t" << Amount << " " << CurrencyFrom.CurrencyCode() << " = "
			<< CurrencyFrom.ConvertToUSD(Amount) << " USD\n";

		if (CurrencyTo.CurrencyCode() == "USD")
			return;

		float AmountCurrencyTo = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);

		_PrintCurrencyCard(CurrencyTo, "Converting from USD to:");

		cout << "\n\t\t\t\t\t" << Amount << " " << CurrencyFrom.CurrencyCode() << " = " << AmountCurrencyTo << " " << CurrencyTo.CurrencyCode();
		
	}

public:

	static void ShowCurrencyCalculateScreen()
	{
		char YesOrNo = 'y';

		while (tolower(YesOrNo) == 'y')
		{
			_DrawScreenHeader("\t Currency Calculate Screen");

			_CurrencyCalculate();

			YesOrNo = clsInputValidate::ReadChar("\n\n\t\t\t\t\tDo you want to perform another calculattion? y/n? ");
		}
		
	}

};

