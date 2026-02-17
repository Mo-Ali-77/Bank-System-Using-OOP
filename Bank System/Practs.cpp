#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include <iomanip>
#include "clsUtil.h"
using namespace std;


// Try as much as possible to separate the UI from the Object.


// All Functions of Project CRUD:

//void ReadClientInfo(clsBankClient& ClientCard)
//{
//	ClientCard.FirstName = clsInputValidate::ReadString("\nEnter First Name: ");
//	ClientCard.LastName = clsInputValidate::ReadString("\nEnter Last Name: ");
//	ClientCard.Email = clsInputValidate::ReadString("\nEnter Email: ");
//	ClientCard.Phone = clsInputValidate::ReadString("\nEnter Phone: ");
//	ClientCard.PinCode = clsInputValidate::ReadString("\nEnter PinCode: ");
//	cout << "\nEnter Account Balance: ";
//	ClientCard.AccountBalance = clsInputValidate::ReadFloatNumber();
//}
//
//void UpdateClient()
//{
//	string AccountNumber = clsInputValidate::ReadString("\nPlease Enter Client Account Number: ");
//
//	while (!(clsBankClient::IsClientExisit(AccountNumber)))
//	{
//		cout << "\nAccount Number is NOT Found, Choose annother one: ";
//		AccountNumber = clsInputValidate::ReadString();
//	}
//
//	clsBankClient Client1 = clsBankClient::Find(AccountNumber);
//	Client1.Print();
//
//	cout << "\n\nUpdate Client Info:";
//	cout << "\n--------------------\n";
//	ReadClientInfo(Client1);
//
//	clsBankClient::enSaveResults SaveResult = Client1.Save();
//
//	switch (SaveResult)
//	{
//	case clsBankClient::enSaveResults::svSucceeded:
//		cout << "\nAccount Updated Successfully :-)\n";
//		Client1.Print();
//		break;
//	case clsBankClient::enSaveResults::svFaildEmptyObject:
//		cout << "\nError Account was NOT saved because it's Empty.";
//			break;
//	}
//	
//
//}
//
//void AddNewClient()
//{
//	string AccountNum = clsInputValidate::ReadString("\nPlease Enter Account Number: ");
//
//	while (clsBankClient::IsClientExisit(AccountNum))
//	{
//		cout << "\nAccount Number is already used, choose another one: ";
//		AccountNum = clsInputValidate::ReadString();
//	}
//
//	clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNum);
//
//	ReadClientInfo(NewClient);
//
//	clsBankClient::enSaveResults SaveResult = NewClient.Save();
//
//	switch (SaveResult)
//	{
//	case clsBankClient::enSaveResults::svSucceeded:
//		cout << "\nAccount Added Successfully :-)\n";
//		NewClient.Print();
//		break;
//
//	case clsBankClient::enSaveResults::svFaildEmptyObject:
//		cout << "\nError Account was not saved because it's empty.";
//		break;
//
//	case clsBankClient::enSaveResults::svFaildAccountNumberExists:
//		cout << "\nError account was not saved because account number is used!\n";
//		break;
//	}
//}
//
//void DeleteClient()
//{
//	string AccountNumber = clsInputValidate::ReadString("\nPlease enter Account Number: ");
//
//	while (!clsBankClient::IsClientExisit(AccountNumber))
//	{
//		cout << "\nAccount Number is NOT found, choose another one: ";
//		AccountNumber = clsInputValidate::ReadString();
//	}
//
//	clsBankClient Client = clsBankClient::Find(AccountNumber);
//	Client.Print();
//
//	char Answer = 'n';
//	cout << "\nAre you sure you want delete this Client y/n? ";
//	cin >> Answer;
//
//	if (tolower(Answer) == 'y')
//	{
//		if (Client.Delete())
//		{
//			cout << "\nClient Deleted Successfully :-)\n";
//			Client.Print();
//		}
//		else
//		{
//			cout << "\nError Client was NOT deleted\n";
//		}
//	}
//
//}
//
//void PrintClientRecordLine(clsBankClient Client)
//{
//
//	cout << "| " << setw(15) << left << Client.AccountNumber();
//	cout << "| " << setw(20) << left << Client.FullName();
//	cout << "| " << setw(12) << left << Client.Phone;
//	cout << "| " << setw(20) << left << Client.Email;
//	cout << "| " << setw(10) << left << Client.PinCode;
//	cout << "| " << setw(12) << left << Client.AccountBalance;
//
//}
//
//void ShowClientList()
//{
//	vector <clsBankClient> vClients = clsBankClient::GetClientsList();
//
//	cout << "\n\t\t\t\t\tClient List (" << vClients.size() << ") Client(s)\t\t\t\t\t";
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n" << endl;
//
//	cout << "| " << left << setw(15) << "Accout Number";
//	cout << "| " << left << setw(20) << "Client Name";
//	cout << "| " << left << setw(12) << "Phone";
//	cout << "| " << left << setw(20) << "Email";
//	cout << "| " << left << setw(10) << "Pin Code";
//	cout << "| " << left << setw(12) << "Balance";
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n" << endl;
//
//	if (vClients.size() == 0)
//		cout << "\t\t\t\tNo Clients Available In the System!";
//	else
//		for (clsBankClient& C : vClients)
//		{
//			PrintClientRecordLine(C);
//			cout << endl;
//		}
//
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n" << endl;
//}
//
//void PrintClientRecordBalanceLine(clsBankClient Client)
//{
//
//	cout << "| " << setw(15) << left << Client.AccountNumber();
//	cout << "| " << setw(40) << left << Client.FullName();
//	cout << "| " << setw(12) << left << Client.AccountBalance;
//
//}
//
//void ShowTotalBalances()
//{
//
//	vector <clsBankClient> vClients = clsBankClient::GetClientsList();
//
//	cout << "\n\t\t\t\t\tBalances List (" << vClients.size() << ") Client(s).";
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n" << endl;
//
//	cout << "| " << left << setw(15) << "Accout Number";
//	cout << "| " << left << setw(40) << "Client Name";
//	cout << "| " << left << setw(12) << "Balance";
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n" << endl;
//
//	double TotalBalances = clsBankClient::GetTotalBalances();
//
//	if (vClients.size() == 0)
//		cout << "\t\t\t\tNo Clients Available In the System!";
//	else
//
//		for (clsBankClient &Client : vClients)
//		{
//			PrintClientRecordBalanceLine(Client);
//			cout << endl;
//		}
//
//	cout << "\n_______________________________________________________";
//	cout << "_________________________________________\n" << endl;
//	cout << "\t\t\t\t\t   Total Balances = " << TotalBalances << endl;
//	cout << "\t\t\t\t\t   ( " << clsUtil::NumberToText(TotalBalances) << ")";
//}


// Main Function

//int main()
//{
//	/*cout << "Is Number 5 Between 1 and 10: ";
//	cout << clsInputValidate::IsNumberBetween(5,1,10);
//
//	cout << "\n\nIs Date 1/1/2022 Between 1/1/2022 and 1/1/2030: ";
//	cout << clsInputValidate::IsDateBetween(clsDate(1, 1, 2022), clsDate(1, 1, 2022), clsDate(1, 1, 2030));
//
//	cout << "\n\nIs Date 4/2/2026 Between 1/1/2022 and 1/1/2030: ";
//	cout << clsInputValidate::IsDateBetween(clsDate(4, 2, 2026), clsDate(1, 1, 2022), clsDate(1, 1, 2030));
//
//	cout << "\n\nIs Date 4/2/2026 Between 1/1/2030 and 1/1/2022: ";
//	cout << clsInputValidate::IsDateBetween(clsDate(4, 2, 2026), clsDate(1, 1, 2030), clsDate(1, 1, 2022));*/
//
//	/*cout << "\n\nEnter Int Number:\n";
//	cout << clsInputValidate::ReadIntNumber("Invalid Number, Enter again: ");
//
//	cout << "\n\nEnter Int Number Between Range [1:5] :\n";
//	cout << clsInputValidate::ReadIntNumberBetween(1, 5, "Number is NOT within range, Enter a valid one: ");
//
//	cout << "\n\nEnter Double Number Between Range [1.0:5.0] :\n";
//	cout << clsInputValidate::ReadDbNumberBetween(1.0, 5.0, "Number is NOT within range, Enter a valid one: ");
//
//	cout << "\n\nIS Valid Date 35/12/2026 : ";
//	cout << clsInputValidate::IsValidDate(clsDate(35,12,2026));
//
//	cout << "\n\nIS Valid Date 31/12/2026 : ";
//	cout << clsInputValidate::IsValidDate(clsDate(31, 12, 2026));*/
//
//	/*clsBanklClient Client1 = clsBanklClient::Find("A101");
//	Client1.Print();
//
//	clsBanklClient Client2 = clsBanklClient::Find("A107", "000");
//	Client2.Print();*/
//
//	//UpdateClient();
//
//	//AddNewClient();
//
//	//DeleteClient();
//
//	//ShowClientList();
//
//	//ShowTotalBalances();
//
//	system("pause>0");
//	return 0;
//}