#pragma once
#include "clsScreen.h"
#include <vector>
#include "clsCurrency.h"
#include <iomanip>


class clsListCurrenciesScreen : clsScreen
{
	static void _PrintCurrencyRecordLine(clsCurrency Currency)
	{

		cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
		cout << "| " << setw(8) << left << Currency.CurrencyCode();
		cout << "| " << setw(45) << left << Currency.CurrencyName();
		cout << "| " << setw(10) << left << Currency.Rate();

	}

	static void _AllListCurrencies()
	{
		vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
		_DrawScreenHeader("\t Currencies List Screen", "(" + to_string(vCurrencies.size()) + ") Currency.");

		cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
		cout << "| " << left << setw(8) << "Code";
		cout << "| " << left << setw(45) << "Name";
		cout << "| " << left << setw(10) << "Rate/(1$)";
		cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________\n" << endl;
		
		if(vCurrencies.size() == 0)
			cout << "\t\t\t\tNo Currencies Available In the System!";
		else
			for (clsCurrency& C : vCurrencies)
			{
				_PrintCurrencyRecordLine(C);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t______________________________________________________________________________________________________\n" << endl;
	}

public:

	static void ShowListCurrenciesScreen()
	{
		_AllListCurrencies();
	}
};

