#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include <vector>
#include "clsUtil.h"
#include <iomanip>

class clsTotalBalancesScreen : protected clsScreen
{
	static void _PrintClientRecordBalanceLine(clsBankClient Client)
	{
		cout << setw(25) << left << "" << "| " << setw(15) << left << Client.AccountNumber();
		cout << "| " << setw(40) << left << Client.FullName();
		cout << "| " << setw(12) << left << Client.AccountBalance;
	}

	static void _TotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();
		string Title = "\tBalances List Screen",
		SubTitle = "\t(" + to_string(vClients.size()) + ") Client(s).";
		
		_DrawScreenHeader(Title, SubTitle);

		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(25) << left << "" << "| " << left << setw(15) << "Accout Number";
		cout << "| " << left << setw(40) << "Client Name";
		cout << "| " << left << setw(12) << "Balance";
		cout << setw(25) << left << "" << "\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		if (vClients.size() == 0)
		{
			cout << "\t\t\t\tNo Clients Available In the System!";
		}
		else
		{
			for (clsBankClient& Client : vClients)
			{
				_PrintClientRecordBalanceLine(Client);
				cout << endl;
			}
		}

		double TotalBalances = clsBankClient::GetTotalBalances();

		cout << setw(25) << left << "" << "\n\t\t_______________________________________________________";
		cout << "__________________________\n" << endl;

		cout << setw(8) << left << "" << "\t\t\t\tTotal Balances = " << TotalBalances << endl << endl;
		cout << setw(8) << left << "" << "\t\t\t\t( " << clsUtil::NumberToText(TotalBalances) << ")";
	}

public:

	static void ShowTotalBalances()
	{
		_TotalBalances();
	}
};

