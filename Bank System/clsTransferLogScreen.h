#pragma once
#include "clsScreen.h"
#include <vector>
#include "clsBankClient.h"
#include <iomanip>

class clsTransferLogScreen : protected clsScreen
{
    static void _PrintTransferLogRecordLine(clsBankClient::stTransferRegisterLog TransferLogRecord)
    {
        cout << setw(8) << left << "" << "| " << setw(23) << left << TransferLogRecord.DateTime;
        cout << "| " << setw(8) << left << TransferLogRecord.SourceAccount;
        cout << "| " << setw(8) << left << TransferLogRecord.DestintionAccount;
        cout << "| " << setw(8) << left << TransferLogRecord.Amount;
        cout << "| " << setw(10) << left << TransferLogRecord.S_Balance;
        cout << "| " << setw(10) << left << TransferLogRecord.Des_Balance;
        cout << "| " << setw(8) << left << TransferLogRecord.UserName;

    }

    static void _TransferLogList()
    {
        vector <clsBankClient::stTransferRegisterLog> vTRL = clsBankClient::GetTransferRegisterLog();

        _DrawScreenHeader("\t TransferLogScreen", "\t   (" + to_string(vTRL.size()) + ") Records(s).");

        cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________\n" << endl;

        if (vTRL.size() == 0)
            cout << "\t\t\t\tNo Transfers Available In the System!";
        else

            for (clsBankClient::stTransferRegisterLog& Record : vTRL)
            {

                _PrintTransferLogRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t________________________________________________________________________________________________\n" << endl;

    }

public:

	static void ShowTransferLogScreen()
	{
        _TransferLogList();
	}
};

