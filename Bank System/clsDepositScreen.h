#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
class clsDepositScreen : protected clsScreen
{
	static void _PrintClient(clsBankClient Client)
	{

		cout << "\n\t\t\t\t\tClient Card:";
		cout << "\n\t\t\t\t\t------------------";
		cout << "\n\t\t\t\t\tFirstName: " << Client.FirstName;
		cout << "\n\t\t\t\t\tLastName: " << Client.LastName;
		cout << "\n\t\t\t\t\tFullName: " << Client.FullName();
		cout << "\n\t\t\t\t\tEmail: " << Client.Email;
		cout << "\n\t\t\t\t\tPhone: " << Client.Phone;
		cout << "\n\t\t\t\t\tAcc. Number: " << Client.AccountNumber();
		cout << "\n\t\t\t\t\tPassword: " << Client.PinCode;
		cout << "\n\t\t\t\t\tBalance: " << Client.AccountBalance;
		cout << "\n\t\t\t\t\t------------------\n";

	}


	static void _DepositScreen()
	{
		string AccountNumber = clsInputValidate::ReadString("\n\t\t\t\t\tPlease Enter Account Number: ");

		while(!(clsBankClient::IsClientExisit(AccountNumber)))
		{
			cout << "\n\t\t\t\t\tClient with [" << AccountNumber << "] does not exist.\n";
			AccountNumber = clsInputValidate::ReadString("\n\t\t\t\t\tPlease Enter Account Number: ");
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		double Amount = 0;
		cout << "\n\t\t\t\t\tPlease Enter Deposit amount? ";
		Amount = clsInputValidate::ReadDbNumber();

		char Answer = clsInputValidate::ReadChar("\n\t\t\t\t\tAre you sure you want to performe this transactions? y/n? ");

		if (tolower(Answer) == 'y')
		{
			Client.Deposit(Amount);
			cout << "\n\t\t\t\t\tAmount Deposit Succsessfully.\n";
			cout << "\n\t\t\t\t\tNew Balance is: " << Client.AccountBalance;
		}
		else
		{
			cout << "\n\t\t\t\t\tOperation was cancled.\n";
		}
	}

public:

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("\tDeposit Screen");
		_DepositScreen();
	}
};

