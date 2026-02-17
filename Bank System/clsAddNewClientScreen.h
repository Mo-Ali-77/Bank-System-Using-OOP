#pragma once
#include "clsScreen.h"
#include"clsBankClient.h"
#include "clsInputValidate.h"
class clsAddNewClientScreen :protected clsScreen
{

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

	static void _AddNewClient()
	{
		string AccountNum = clsInputValidate::ReadString("\n\t\t\t\t\tPlease Enter Account Number: ");

		while (clsBankClient::IsClientExisit(AccountNum))
		{
			cout << "\n\t\t\t\t\tAccount Number is already used, choose another one: ";
			AccountNum = clsInputValidate::ReadString();
		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNum);

		_ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResult = NewClient.Save();

		switch (SaveResult)
		{
		case clsBankClient::enSaveResults::svSucceeded:
			cout << "\n\t\t\t\t\tAccount Added Successfully :-)\n";
			_PrintClient(NewClient);
			break;

		case clsBankClient::enSaveResults::svFaildEmptyObject:
			cout << "\n\t\t\t\t\tError Account was not saved because it's empty.";
			break;

		case clsBankClient::enSaveResults::svFaildAccountNumberExists:
			cout << "\n\t\t\t\t\tError account was not saved because account number is used!\n";
			break;
		}
	}

public:
	
	static void ShowAddNewClientsScreen()
	{
		if (!(_CheckAccessRights(clsUser::enPermissions::pAddNewClient)))
			return;
		_DrawScreenHeader("\tAdd New Client Screen");
		_AddNewClient();
	}

};

