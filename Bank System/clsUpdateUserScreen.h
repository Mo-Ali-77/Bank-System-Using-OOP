#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsUpdateUserScreen :protected clsScreen

{
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permission: ";
        User.Permissions = _ReadPermissionsToSet();
    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }

    static int _ReadPermissionsToSet()
    {
        int Permissions = 0;
        char Answer = 'n';


        cout << "\nDo you want to give full access? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
            return -1;


        cout << "\nDo you want to give access to : \n ";

        cout << "\nShow Client List? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
            Permissions += clsUser::enPermissions::pListClients;


        cout << "\nAdd New Client? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
            Permissions += clsUser::enPermissions::pAddNewClient;


        cout << "\nDelete Client? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
            Permissions += clsUser::enPermissions::pDeleteClient;


        cout << "\nUpdate Client? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
            Permissions += clsUser::enPermissions::pUpdateClient;


        cout << "\nFind Client? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
            Permissions += clsUser::enPermissions::pFindClient;


        cout << "\nTransactions? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
            Permissions += clsUser::enPermissions::pTransactions;


        cout << "\nManage Users? y/n? ";
        cin >> Answer;
        if (tolower(Answer) == 'y')
            Permissions += clsUser::enPermissions::pManageUsers;


        if (Permissions == 127)
            return -1;

        return Permissions;
    }

    static void _UpdateUser()
    {
        string UserName = "";

        cout << "\nPlease Enter User UserName: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nAccount number is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);

        _PrintUser(User);

        cout << "\nAre you sure you want to update this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";


            _ReadUserInfo(User);

            clsUser::enSaveResults SaveResult;

            SaveResult = User.Save();

            switch (SaveResult)
            {
            case  clsUser::enSaveResults::svSucceeded:
            {
                cout << "\nUser Updated Successfully :-)\n";

                _PrintUser(User);
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError User was not saved because it's Empty";
                break;

            }

            }

        }
    }

public:

    static void ShowUpdateUserScreen()
    {
        _DrawScreenHeader("\tUpdate User Screen");
        _UpdateUser();

    }
};

