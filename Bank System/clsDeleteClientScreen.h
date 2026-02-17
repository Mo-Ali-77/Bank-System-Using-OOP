#pragma once
#include"clsScreen.h"
class clsDeleteClientScreen : protected clsScreen
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

	static void _DeleteClient()
	{
		string AccountNumber = clsInputValidate::ReadString("\n\t\t\t\t\tPlease enter Account Number: ");
	
		while (!clsBankClient::IsClientExisit(AccountNumber))
		{
			cout << "\n\t\t\t\t\tAccount Number is NOT found, choose another one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
	
		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);
	
		char Answer = 'n';
		cout << "\n\t\t\t\t\tAre you sure you want delete this Client y/n? ";
		cin >> Answer;
	
		if (tolower(Answer) == 'y')
		{
			if (Client.Delete())
			{
				cout << "\n\t\t\t\t\tClient Deleted Successfully :-)\n";
				_PrintClient(Client);
			}
			else
			{
				cout << "\n\t\t\t\t\tError Client was NOT deleted\n";
			}
		}
	
	}

public:

	static void ShowDeleteClientScreen()
	{
		if (!(_CheckAccessRights(clsUser::enPermissions::pDeleteClient)))
			return;

		_DrawScreenHeader("\tDelete Client Screen");

		_DeleteClient();
	}

};

