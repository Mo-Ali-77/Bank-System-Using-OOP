#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsBankClient.h"
#include<iomanip>
class clsUpdateClientScreen : protected clsScreen
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

	static void _ReadClientInfo(clsBankClient& ClientCard)
	{
		ClientCard.FirstName = clsInputValidate::ReadString("\n\t\t\t\t\tEnter First Name: ");
		ClientCard.LastName = clsInputValidate::ReadString("\n\t\t\t\t\tEnter Last Name: ");
		ClientCard.Email = clsInputValidate::ReadString("\n\t\t\t\t\tEnter Email: ");
		ClientCard.Phone = clsInputValidate::ReadString("\n\t\t\t\t\tEnter Phone: ");
		ClientCard.PinCode = clsInputValidate::ReadString("\n\t\t\t\t\tEnter PinCode: ");
		cout << "\n\t\t\t\t\tEnter Account Balance: ";
		ClientCard.AccountBalance = clsInputValidate::ReadFloatNumber();
	}

	static void _UpdateClient()
	{
		string AccountNumber = clsInputValidate::ReadString("\n\t\t\t\t\tPlease Enter Account Number: ");
	
		while (!(clsBankClient::IsClientExisit(AccountNumber)))
		{
			cout << "\n\t\t\t\t\tAccount Number is NOT Found, Choose annother one: ";
			AccountNumber = clsInputValidate::ReadString();
		}
	
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		_PrintClient(Client1);
	
		char Answer = 'n';
		cout << "\n\t\t\t\t\tAre you sure you want Update this Client y/n? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			cout << "\n\n\t\t\t\t\tUpdate Client Info:";
			cout << "\n\t\t\t\t\t--------------------\n";
			_ReadClientInfo(Client1);

			clsBankClient::enSaveResults SaveResult = Client1.Save();

			switch (SaveResult)
			{
			case clsBankClient::enSaveResults::svSucceeded:
				cout << "\n\t\t\t\t\tAccount Updated Successfully :-)\n";
				_PrintClient(Client1);
				break;

			case clsBankClient::enSaveResults::svFaildEmptyObject:
				cout << "\n\t\t\t\t\tError Account was NOT saved because it's Empty.";
				break;
			}
		}
	}


public:

	static void ShowUpdateClientScreen()
	{
		if (!(_CheckAccessRights(clsUser::enPermissions::pUpdateClient)))
			return;

		_DrawScreenHeader("\tUpdate Client Screen");

		_UpdateClient();
	}
};

