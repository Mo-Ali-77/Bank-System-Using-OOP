#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "Gloabl.h"
#include "clsMainScreen.h"

class clsLoginScreen : protected clsScreen
{
	static void _ShowLockedAfter3TimesLogin()
	{
		_DrawScreenHeader("\t Locked Screen");

		cout << "\n\t\t\t\t\tYou are Locked after 3 Trials Login.\n\n";
	}

	static void _Login()
	{
		string UserName, Password;
		
		short _3Times = 3;

		while (_3Times >= 1)
		{
			UserName = clsInputValidate::ReadString("\t\t\t\t\tEnter UserName: ");
			Password = clsInputValidate::ReadString("\t\t\t\t\tEnter Password: ");

			CurrentUser = clsUser::Find(UserName, Password);
			if (!CurrentUser.IsEmpty())
				break;
			--_3Times;
			cout << "\n\t\t\t\t\tInvalid UserName/Password.";
			cout << "\n\t\t\t\t\tYou have " << _3Times << " Trials to login\n\n";
		}

		if (_3Times > 0)
		{
			CurrentUser.SaveToLogFile();
			clsMainScreen::ShowMainMenue();
		}
			
		else
		{
			_ShowLockedAfter3TimesLogin();
			exit(0);
		}
			
	}

public:

	static void ShowLoginScreen()
	{
		_DrawScreenHeader("\t    Login Scren");
		
		_Login();
	}
};

