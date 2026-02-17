#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include"clsUser.h"

class clsDeleteUserScreen : protected clsScreen
{
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

    static void _DeleteUser()
    {
        string UserName = "";

        cout << "\n\t\t\t\t\tPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\n\t\t\t\t\tUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);
        _PrintUser(User);

        cout << "\n\t\t\t\t\tAre you sure you want to delete this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            if (User.Delete())
            {
                cout << "\n\t\t\t\t\tUser Deleted Successfully :-)\n";
                _PrintUser(User);
            }
            else
            {
                cout << "\n\t\t\t\t\tError User Was not Deleted\n";
            }
        }
    }


public:

    static void ShowDeleteUserScreen()
    {
        _DrawScreenHeader("\tDelete User Screen");
        _DeleteUser();
    }

};

