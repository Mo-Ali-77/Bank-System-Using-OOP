#pragma once
#include <iostream>
#include <string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>
#include "clsDate.h"

class clsUser : public clsPerson
{
	enum _enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2 };
	_enMode _Mode;
	string _UserName;
	string _Password;
	int _Permissions = 0;

	bool _MarkedForDelete = false;

    static clsUser _ConvertLinetoUserObject(string Line, string Seperator = "#//#")
    {
        vector<string> vUserData;
        vUserData = clsString::Split(Line, Seperator);

        return clsUser(_enMode::UpdateMode, vUserData[0], vUserData[1], vUserData[2],
            vUserData[3], vUserData[4], vUserData[5], stoi(vUserData[6]));

    }

    static string _ConverUserObjectToLine(clsUser User, string Seperator = "#//#")
    {

        string UserRecord = "";
        UserRecord += User.FirstName + Seperator;
        UserRecord += User.LastName + Seperator;
        UserRecord += User.Email + Seperator;
        UserRecord += User.Phone + Seperator;
        UserRecord += User.UserName + Seperator;
        UserRecord += User.Password + Seperator;
        UserRecord += to_string(User._Permissions);

        return UserRecord;

    }

    static  vector <clsUser> _LoadUsersDataFromFile()
    {

        vector <clsUser> vUsers;

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {

            string Line;


            while (getline(MyFile, Line))
            {

                clsUser User = _ConvertLinetoUserObject(Line);

                vUsers.push_back(User);
            }

            MyFile.close();

        }

        return vUsers;

    }

    static void _SaveUsersDataToFile(vector <clsUser> vUsers)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::out);

        string DataLine;

        if (MyFile.is_open())
        {

            for (clsUser &U : vUsers)
            {
                if (U.MarkedForDelete() == false)
                {
                    DataLine = _ConverUserObjectToLine(U);
                    MyFile << DataLine << endl;

                }

            }

            MyFile.close();

        }

    }

    void _Update()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == UserName)
            {
                U = *this;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

    }

    void _AddNew()
    {

        _AddDataLineToFile(_ConverUserObjectToLine(*this));
    }

    void _AddDataLineToFile(string  stDataLine)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::out | ios::app);

        if (MyFile.is_open())
        {

            MyFile << stDataLine << endl;

            MyFile.close();
        }

    }

    static clsUser _GetEmptyUserObject()
    {
        return clsUser(_enMode::EmptyMode, "", "", "", "", "", "", 0);
    }

    string _ConvertUserLoginToLine(string Seperator = "#//#")
    {
        string UserRecord = "";
        UserRecord += clsDate::GetSystemDateTimeString() + Seperator;
        UserRecord += _UserName + Seperator;
        UserRecord += _Password + Seperator;
        UserRecord += to_string(_Permissions);

        return UserRecord;
    }

    void _SaveToLogFlie()
    {
        string ObjToLine = _ConvertUserLoginToLine();

        fstream MyLogFile;
        MyLogFile.open("LoginRegister.txt", ios::app);

        if (MyLogFile.is_open())
        {
            MyLogFile << ObjToLine << endl;

            MyLogFile.close();
        }
    }

    struct stLoginRegesterRecord;
    static stLoginRegesterRecord _ConvertLoginRegisterLineToRecord(string Line, string Seprator = "#//#")
    {
        vector <string> vLoginRegister = clsString::Split(Line, Seprator);

        stLoginRegesterRecord LRR;
        LRR.DateTime = vLoginRegister[0];
        LRR.UserName = vLoginRegister[1];
        LRR.Password = vLoginRegister[2];
        LRR.Permissions = stoi(vLoginRegister[3]);

        return LRR;
    }

public:

    struct stLoginRegesterRecord
    {
        string DateTime = "";
        string UserName = "";
        string Password = "";
        int Permissions = 0;
    };

    enum enPermissions {eAll = -1, pListClients = 1, pAddNewClient = 2, pDeleteClient = 4, pUpdateClient = 8, pFindClient = 16, pTransactions = 32, pManageUsers = 64};

	clsUser(_enMode Mode, string FirstName, string LastName, string Email, string Phone, string UserName, string Passwor, int Permissons) : clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_UserName = UserName;
		_Password = Passwor;
		_Permissions = Permissons;
	}

	bool IsEmpty()
	{
		return (_Mode == _enMode::EmptyMode);
	}

	bool MarkedForDelete()
	{
		return _MarkedForDelete;
	}

	string GetUserName()
	{
		return _UserName;
	}

	void SetUserName(string UserName)
	{
		_UserName = UserName;
	}
	__declspec(property(get = GetUserName, put = SetUserName)) string UserName;

	string GetPassword()
	{
		return _Password;
	}

	void SetPassword(string Password)
	{
		_Password = Password;
	}
	__declspec(property(get = GetPassword, put = SetPassword)) string Password;

	int GetPermissions()
	{
		return _Permissions;
	}

	void SetPermissions(int Permission)
	{
		_Permissions = Permission;
	}
	__declspec(property(get = GetPermissions, put = SetPermissions)) int Permissions;

    static clsUser Find(string UserName)
    {
        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.UserName == UserName)
                {
                    MyFile.close();
                    return User;
                }
            }

            MyFile.close();

        }

        return _GetEmptyUserObject();
    }

    static clsUser Find(string UserName, string Password)
    {

        fstream MyFile;
        MyFile.open("Users.txt", ios::in);

        if (MyFile.is_open())
        {
            string Line;
            while (getline(MyFile, Line))
            {
                clsUser User = _ConvertLinetoUserObject(Line);
                if (User.UserName == UserName && User.Password == Password)
                {
                    MyFile.close();
                    return User;
                }

            }

            MyFile.close();

        }
        return _GetEmptyUserObject();
    }

    enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildUserExists = 2 };

    enSaveResults Save()
    {

        switch (_Mode)
        {
        case _enMode::EmptyMode:
        {
            if (IsEmpty())
            {
                return enSaveResults::svFaildEmptyObject;
            }
        }

        case _enMode::UpdateMode:
        {
            _Update();
            return enSaveResults::svSucceeded;

            break;
        }

        case _enMode::AddNewMode:
        {
            if (clsUser::IsUserExist(_UserName))
            {
                return enSaveResults::svFaildUserExists;
            }
            else
            {
                _AddNew();
                
                _Mode = _enMode::UpdateMode;
                return enSaveResults::svSucceeded;
            }

            break;
        }
        }

    }

    static bool IsUserExist(string UserName)
    {

        clsUser User = clsUser::Find(UserName);
        return (!User.IsEmpty());
    }

    bool Delete()
    {
        vector <clsUser> _vUsers;
        _vUsers = _LoadUsersDataFromFile();

        for (clsUser& U : _vUsers)
        {
            if (U.UserName == _UserName)
            {
                U._MarkedForDelete = true;
                break;
            }

        }

        _SaveUsersDataToFile(_vUsers);

        *this = _GetEmptyUserObject();

        return true;

    }

    static clsUser GetAddNewUserObject(string UserName)
    {
        return clsUser(_enMode::AddNewMode, "", "", "", "", UserName, "", 0);
    }

    static vector <clsUser> GetUsersList()
    {
        return _LoadUsersDataFromFile();
    }

    bool CheckAccessPermission(enPermissions Permission)
    {
        if (this->Permissions == enPermissions::eAll)
            return true;
        if ((Permission & this->Permissions) == Permission)
            return true;
        else
            return false;
    }

    void SaveToLogFile()
    {
        _SaveToLogFlie();
    }

    static vector<stLoginRegesterRecord> GetLoginRegisterList()
    {
        vector <stLoginRegesterRecord> vLRR;
        fstream RegisterLogFile;

        RegisterLogFile.open("LoginRegister.txt", ios::in);

        if (RegisterLogFile.is_open())
        {
            string Line = "";
            stLoginRegesterRecord LRR;
            while (getline(RegisterLogFile, Line))
            {
                LRR = _ConvertLoginRegisterLineToRecord(Line);
                vLRR.push_back(LRR);
            }

            RegisterLogFile.close();
        }

        return vLRR;
        
    }
};

