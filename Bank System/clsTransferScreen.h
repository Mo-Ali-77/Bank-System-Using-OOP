#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

class clsTransferScreen: protected clsScreen
{
	static clsBankClient _GetClientByAccountNumber(string& AccNum, string AskTransfer)
	{
		
		AccNum = clsInputValidate::ReadString(AskTransfer);
		
		while (!clsBankClient::IsClientExisit(AccNum))
		{
			cout << "\n\t\t\t\t\tAccountNumber (" << AccNum << ") NOT exisit, enter another one: ";
			AccNum = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccNum);

		return Client;
	}

	static void _PrintClientCard(clsBankClient Client)
	{
		cout << "\n\t\t\t\t\tClient Card:";
		cout << "\n\t\t\t\t\t---------------------------";
		cout << "\n\t\t\t\t\tFull Name  : " << Client.FullName();
		cout << "\n\t\t\t\t\tAcc. Number: " << Client.AccountNumber();
		cout << "\n\t\t\t\t\tBalance    : " << Client.AccountBalance;
		cout << "\n\t\t\t\t\t---------------------------\n";
	}

	static void _Transfer()
	{
		string AccNum1, AccNum2;
		
		clsBankClient SourceClient = _GetClientByAccountNumber(AccNum1, "\n\t\t\t\t\tPlease enter Account Number to Transfer From: ");
		_PrintClientCard(SourceClient);

		clsBankClient DestinationClient = _GetClientByAccountNumber(AccNum2, "\n\t\t\t\t\tPlease enter Account Number to Transfer To: ");
		_PrintClientCard(DestinationClient);

		if (!(SourceClient.AccountNumber() == DestinationClient.AccountNumber()))
		{
			float Amount;
			cout << "\n\n\t\t\t\t\tEnter Transfer Amount: ";
			Amount = clsInputValidate::ReadFloatNumberBetween(0, SourceClient.AccountBalance, "\n\t\t\t\t\tAmount Exceeds the available Balance, Enter another Amount? ");

			cout << "\n\t\t\t\t\tAre you sure you want to perform this operation? y/n? ";

			if ((tolower(clsInputValidate::ReadChar()) == 'y') && (SourceClient.Transfer(Amount, DestinationClient)))
			{
				cout << "\n\t\t\t\t\tTransfer done successfully :-)\n";
				_PrintClientCard(SourceClient);
				_PrintClientCard(DestinationClient);
			}
			else
			{
				cout << "\n\t\t\t\t\tConcled operation. :-(";
			}
		}
		else
		{
			cout << "\n\t\t\t\t\tYou Cannot Transfer to Same Account.";
		}
	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\t Transfer Screen");

		_Transfer();
	}

};

