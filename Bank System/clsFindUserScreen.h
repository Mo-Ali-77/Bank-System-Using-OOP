#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsFindUserScreen :protected clsScreen
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
        cout << "\n\t\t\t\t\tUserName    : " << User.UserName;
        cout << "\n\t\t\t\t\tPassword    : " << User.Password;
        cout << "\n\t\t\t\t\tPermissions : " << User.Permissions;
        cout << "\n\t\t\t\t\t___________________\n";

    }

    static void _FindUser()
    {
        string UserName;
        cout << "\n\t\t\t\t\tPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\n\t\t\t\t\tUser is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);

        _PrintUser(User);

        if (User.IsEmpty())
            cout << "\n\t\t\t\t\tUser Empty :-(\n";
        
        else
            cout << "\n\t\t\t\t\tUser Found :-)\n";
            
        
    }

public:

    static void ShowFindUserScreen()
    {
        _DrawScreenHeader("\t  Find User Screen");

        _FindUser();

    }

};

