#pragma once
#include"clsScreen.h"
#include<iostream>
#include"clsBankClient.h"
#include<iomanip>
#include<fstream>



class clsTransferLogScreen : protected clsScreen 
{

private:

	static void _PrintTransferLogRecordLine(clsBankClient::stTransferLogRecord TransferLogRecord)
	{
		cout << setw(8) << left << "" << "| " << setw(23) << TransferLogRecord.DateTime;
		cout << "| " << setw(8) << left << TransferLogRecord.SourceAccountNumber;
		cout << "| " << setw(8) << left << TransferLogRecord.DestinationAccountNumber;
		cout << "| " << setw(8) << left << TransferLogRecord.Amount;
		cout << "| " << setw(12) << left << TransferLogRecord.srcBalanceAfter;
		cout << "| " << setw(12) << left << TransferLogRecord.destBalanceAfter;
		cout << "| " << setw(8) << left << TransferLogRecord.UserName;

	}


public:

	static void ShowTarnsferLogScreen()
	{
		vector <clsBankClient::stTransferLogRecord> vTransferLogRecord = clsBankClient::GetTransferLogList();

		string Title = "\tTransfer Log List Screen ";
		string SubTitle = "\t	(" + to_string(vTransferLogRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t__________________________________________";
		cout << "________________________________________________\n\n";

		cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
		cout << "| " << left << setw(8) << "s.Acct";
		cout << "| " << left << setw(8) << "d.Acct";
		cout << "| " << left << setw(8) << "Amount";
		cout << "| " << left << setw(12) << "s.Balance";
		cout << "| " << left << setw(12) << "d.Balance";
		cout << "| " << left << setw(8) << "User";

		cout << setw(8) << left << "" << "\n\t__________________________________________";
		cout << "________________________________________________\n\n";

		if (vTransferLogRecord.size() == 0)
			cout << "\t\t\t\tNo Transfers Available In the System ! ";

		else
			for (clsBankClient::stTransferLogRecord Record : vTransferLogRecord )
			{
				_PrintTransferLogRecordLine(Record);
				cout << endl;
			}
		cout << setw(8) << left << "" << "\n\t__________________________________________";
		cout << "________________________________________________\n";
	}
};
