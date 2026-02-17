#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "Gloabl.h"
#include "clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{
	static void _Login()
	{
		string UserName, Password;
		
		while (true)
		{
			UserName = clsInputValidate::ReadString("\t\t\t\t\tEnter UserName: ");
			Password = clsInputValidate::ReadString("\t\t\t\t\tEnter Password: ");

			CurrentUser = clsUser::Find(UserName, Password);
			if (!CurrentUser.IsEmpty())
				break;

			cout << "\n\t\t\t\t\tInvalid UserName/Password.\n\n";
		}

		clsMainScreen::ShowMainMenue();
	}

public:

	static void ShowLoginScreen()
	{
		_DrawScreenHeader("\t    Login Scren");
		
		_Login();
	}
};

