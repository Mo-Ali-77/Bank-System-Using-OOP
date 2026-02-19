#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsAddNewUserScreen : protected clsScreen
{
	static int _ReadPermissionsToSet()
	{
        int Permissions = 0;
        char Answer = 'n';


        cout << "\n\t\t\t\t\tDo you want to give full access? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
            return -1;
        

        cout << "\n\t\t\t\t\tDo you want to give access to : \n ";

        cout << "\n\t\t\t\t\tShow Client List? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
            Permissions += clsUser::enPermissions::pListClients;
        

        cout << "\n\t\t\t\t\tAdd New Client? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
            Permissions += clsUser::enPermissions::pAddNewClient;
        

        cout << "\n\t\t\t\t\tDelete Client? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
            Permissions += clsUser::enPermissions::pDeleteClient;
        

        cout << "\n\t\t\t\t\tUpdate Client? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
            Permissions += clsUser::enPermissions::pUpdateClient;
        

        cout << "\n\t\t\t\t\tFind Client? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
            Permissions += clsUser::enPermissions::pFindClient;
        

        cout << "\n\t\t\t\t\tTransactions? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
            Permissions += clsUser::enPermissions::pTransactions;
        

        cout << "\n\t\t\t\t\tManage Users? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
            Permissions += clsUser::enPermissions::pManageUsers;
        
        cout << "\n\t\t\t\t\tShow Login Register? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
            Permissions += clsUser::enPermissions::pLoginRegister;

        if (Permissions == 255)
            return -1;

        return Permissions;
	}

	static void _ReadUSerInfo(clsUser& User)
	{
		User.FirstName = clsInputValidate::ReadString("\n\t\t\t\t\tEnter FirstName: ");

		User.LastName = clsInputValidate::ReadString("\n\t\t\t\t\tEnter LastName: ");

		User.Email = clsInputValidate::ReadString("\n\t\t\t\t\tEnter Email: ");

		User.Phone = clsInputValidate::ReadString("\n\t\t\t\t\tEnter Phone: ");

		User.Password = clsInputValidate::ReadString("\n\t\t\t\t\tEnter Password: ");

		cout << "\n\t\t\t\t\tEnter Permission: ";
		User.Permissions = _ReadPermissionsToSet();
	}

    static void _PrintUser(clsUser User)
    {
        cout << "\n\t\t\t\t\tUser Card:";
        cout << "\n\t\t\t\t\t___________________";
        cout << "\n\t\t\t\t\tFirstName   : " << User.FirstName;
        cout << "\n\t\t\t\t\tLastName    : " << User.LastName;
        cout << "\n\t\t\t\t\tFull Name   : " << User.FullName();
        cout << "\n\t\t\t\t\tEmail       : " << User.Email;
        cout << "\n\t\t\t\t\tPhone       : " << User.Phone;
        cout << "\n\t\t\t\t\tUser Name   : " << User.UserName;
        cout << "\n\t\t\t\t\tPassword    : " << User.Password;
        cout << "\n\t\t\t\t\tPermissions : " << User.Permissions;
        cout << "\n\t\t\t\t\t___________________\n";

    }


	static void _AddNewUser()
	{
		string UserName = clsInputValidate::ReadString("\t\t\t\t\tPlease Enter UserName: ");

		while (clsUser::IsUserExist(UserName))
		{
			cout << "\t\t\t\t\tUserName is already Used, Choose another one: ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadUSerInfo(NewUser);

        clsUser::enSaveResults  SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case clsUser::enSaveResults::svSucceeded:
            cout << "\n\t\t\t\t\tUser Addeded Successfully :-)\n";
            _PrintUser(NewUser);
            break;

        case clsUser::enSaveResults::svFaildEmptyObject:
            cout << "\n\t\t\t\t\tError User was not saved because it's Empty";
            break;
        
        case clsUser::enSaveResults::svFaildUserExists:
            cout << "\n\t\t\t\t\tError User was not saved because UserName is used!\n";
            break;

        }

	}

public:

	static void ShowAddNewUser()
	{
        _DrawScreenHeader("\tAdd New User Screen");
		_AddNewUser();
	}
};

