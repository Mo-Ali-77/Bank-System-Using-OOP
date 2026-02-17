#pragma once
#include<iostream>
#include<string>
#include "clsPerson.h"
#include "clsString.h"
#include <vector>
#include <fstream>


class clsBankClient : public clsPerson
{
	enum _enMode {EmptyMode = 0, UpdateMode = 1, AddNewClientMode = 2};
	_enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MakForDelete = false;

	static clsBankClient _ConvertLinetoClientObject(string Line, string Seprater = "#//#")
	{
		vector <string> vClient;
		vClient = clsString::Split(Line, Seprater);

		// return Object
		return clsBankClient(_enMode::UpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4], vClient[5], stoi(vClient[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient ClientCard, string Separater = "#//#") 
	{
		string stClientRecord = "";

		stClientRecord += ClientCard.FirstName + Separater;
		stClientRecord += ClientCard.LastName + Separater;
		stClientRecord += ClientCard.Email + Separater;
		stClientRecord += ClientCard.Phone + Separater;
		stClientRecord += ClientCard.AccountNumber() + Separater;
		stClientRecord += ClientCard.PinCode + Separater;
		stClientRecord += to_string(ClientCard.AccountBalance);

		return stClientRecord;

	}

	static vector<clsBankClient> _LoadClientsDataFromFile()
	{
		vector <clsBankClient> vClients;

		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				vClients.push_back(Client);
			}

			MyFile.close();
		}

		return vClients;
	}

	static void _SaveClientsDataToFile(vector <clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		if (MyFile.is_open())
		{
			string DataLine;
			for (clsBankClient& C : vClients)
			{
				if (C._MakForDelete == false)
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
			}
			MyFile.close();
		}
	}

	void _Update()
	{
		vector <clsBankClient> _vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}

		_SaveClientsDataToFile(_vClients);
	}

	void _AddNewClient()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			MyFile.close();
		}
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(_enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

public:

	clsBankClient(_enMode Mode, string FirstName, string LastName, string Email, string Phone, string AccountNumber, string PinCode, float AccountBalance) :clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{ 
		return (_Mode == _enMode::EmptyMode);
	}

	// Read only property
	string AccountNumber()
	{
		return _AccountNumber;
	}
	
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}
	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;


	// No UI Related code inside object.
	/*void Print()
	{
		cout << "\nClient Card:";
		cout << "\n------------------";
		cout << "\nFirstName: " << FirstName;
		cout << "\nLastName: " << LastName;
		cout << "\nFullName: " << FullName();
		cout << "\nEmail: " << Email;
		cout << "\nPhone: " << Phone;
		cout << "\nAcc. Number: " << _AccountNumber;
		cout << "\nPassword: " << _PinCode;
		cout << "\nBalance: " << _AccountBalance;
		cout << "\n------------------\n";
	}*/

	static clsBankClient Find(string AccountNumber)
	{
		vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); // read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in); // read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsBankClient Client = _ConvertLinetoClientObject(Line);
				if (Client.AccountNumber() == AccountNumber && Client.PinCode == PinCode)
				{
					MyFile.close();
					return Client;
				}
				vClients.push_back(Client);
			}
			MyFile.close();
		}
		return _GetEmptyClientObject();
	}

	static bool IsClientExisit(string AccountNumber)
	{
		clsBankClient TempClient = clsBankClient::Find(AccountNumber);

		return !(TempClient.IsEmpty());
	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2};

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case _enMode::EmptyMode:
			return enSaveResults::svFaildEmptyObject;
		
		case _enMode::UpdateMode:
			_Update();
			return enSaveResults::svSucceeded;

		case _enMode::AddNewClientMode:

			if (clsBankClient::IsClientExisit(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNewClient();
				_Mode = _enMode::UpdateMode;
				
				return enSaveResults::svSucceeded;
			}
			
		}
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(_enMode::AddNewClientMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector <clsBankClient> vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : vClients)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MakForDelete = true;

				_SaveClientsDataToFile(vClients);

				*this = _GetEmptyClientObject();
				return true;
			}
		}

		return false;
	}

	static vector <clsBankClient> GetClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances()
	{
		vector <clsBankClient> vClients = GetClientsList();
		double TotalBalances = 0;

		for (clsBankClient& C : vClients)
		{
			TotalBalances += C.AccountBalance;
		}

		return TotalBalances;
	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
			return true;
		}
	}

};

