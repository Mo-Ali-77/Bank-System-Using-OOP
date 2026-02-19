#pragma once
#include "clsScreen.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsUpdateUserScreen :protected clsScreen

{
    static void _ReadUserInfo(clsUser& User)
    {
        cout << "\n\t\t\t\t\tEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\n\t\t\t\t\tEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\n\t\t\t\t\tEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\n\t\t\t\t\tEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\n\t\t\t\t\tEnter Password: ";
        User.Password = clsInputValidate::ReadString();

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

    static void _UpdateUser()
    {
        string UserName = "";

        cout << "\n\t\t\t\t\tPlease Enter User UserName: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\n\t\t\t\t\tAccount number is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(UserName);

        _PrintUser(User);

        cout << "\n\t\t\t\t\tAre you sure you want to update this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\n\t\t\t\t\tUpdate User Info:";
            cout << "\n\t\t\t\t\t____________________\n";


            _ReadUserInfo(User);

            clsUser::enSaveResults SaveResult;

            SaveResult = User.Save();

            switch (SaveResult)
            {
            case  clsUser::enSaveResults::svSucceeded:
            {
                cout << "\n\t\t\t\t\tUser Updated Successfully :-)\n";

                _PrintUser(User);
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\n\t\t\t\t\tError User was not saved because it's Empty";
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

