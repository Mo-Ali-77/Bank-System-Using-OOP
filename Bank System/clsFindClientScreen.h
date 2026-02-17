#pragma once
#include"clsScreen.h"
#include"clsInputValidate.h"
#include"clsBankClient.h"
class clsFindClientScreen : protected clsScreen
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

	static void _FindClient()
	{
		string AccountNumber = clsInputValidate::ReadString("\n\t\t\t\t\tPlease Enter Account Number: ");

		while (!(clsBankClient::IsClientExisit(AccountNumber)))
		{
			cout << "\n\t\t\t\t\tAccount Number is NOT Found, Choose annother one: ";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		if (!(Client1.IsEmpty()))
		{
			_PrintClient(Client1);
			cout << "\n\t\t\t\t\tClient Found :-)\n";
		}
		else
		{
			cout << "\n\t\t\t\t\tClient NOT Found\n";
		}
	}

public:

	static void ShowFindClientScreen()
	{
		if (!(_CheckAccessRights(clsUser::enPermissions::pFindClient)))
			return;

		_DrawScreenHeader("\tFind Client Screen");
		_FindClient();
	}

};

