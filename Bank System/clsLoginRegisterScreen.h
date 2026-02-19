#pragma once
#include "clsScreen.h"
#include <vector>
#include "clsUser.h"
class clsLoginRegisterScreen : protected clsScreen
{
	static void _PrintLoginRegisterRecordLine(clsUser::stLoginRegesterRecord LoginRegisterRecord)
	{

		cout << setw(8) << left << "" << "| " << setw(35) << left << LoginRegisterRecord.DateTime;
		cout << "| " << setw(20) << left << LoginRegisterRecord.UserName;
		cout << "| " << setw(20) << left << LoginRegisterRecord.Password;
		cout << "| " << setw(10) << left << LoginRegisterRecord.Permissions;
	}

	static void _LoginRegisterList()
	{
		vector <clsUser::stLoginRegesterRecord> vLoginRecords = clsUser::GetLoginRegisterList();

		_DrawScreenHeader("\tLogin Register List Screen", "\t   (" + to_string(vLoginRecords.size()) + ") Record(s).");

		cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________\n" << endl;

		if (vLoginRecords.size() == 0)
			cout << "\t\t\t\tNo Logins Available In the System!";
		else

			for (clsUser::stLoginRegesterRecord& Record : vLoginRecords)
			{

				_PrintLoginRegisterRecordLine(Record);
				cout << endl;
			}

		cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________\n" << endl;
	}

public:

	static void ShowLoginRegisterScreen()
	{
		if (!(_CheckAccessRights(clsUser::enPermissions::pLoginRegister)))
			return;

		_LoginRegisterList();
	}
};

