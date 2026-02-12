#pragma once
#include<iostream>
#include<fstream>
#include<iomanip>
#include"clsUser.h"
#include"clsScreen.h"



class clsLoginRegisterScreen : protected clsScreen
{

private:

	static void PrintLoginRegisterRecordLine(clsUser::stLoginRegisterRecord Record) 
	{
		cout << setw(8) << left << "" << "| " << setw(35) << left << Record.DataTime;
		cout << "| " << setw(20) << left << Record.UserName;
		cout << "| " << setw(20) << left << Record.Password;
		cout << "| " << setw(10) << left << Record.Permissions;
	}


public:
	
	static void ShowLoginRegisterScreen()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pLoginRegister))
		{
			return;
		}

		vector <clsUser::stLoginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterList();

		string Title = "\tLogin Register List Screen";
		string SubTitle = "\t\t(" + to_string(vLoginRegisterRecord.size()) + ") Record(s).";

		_DrawScreenHeader(Title, SubTitle);
		cout << setw(8) << left << "" << "\n\t_____________________________________________";
		cout << "___________________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
		cout << "| " << left << setw(20) << "UserName";
		cout << "| " << left << setw(20) << "Password";
		cout << "| " << left << setw(10) << "Permissions";
		cout << setw(8) << left << "" << "\n\t_____________________________________________";
		cout << "___________________________________________________\n" << endl; 

		if (vLoginRegisterRecord.size() == 0)
			cout << "\t\t\tNo Logins Available In the System!";
		else
			for (clsUser::stLoginRegisterRecord Record : vLoginRegisterRecord)
			{
				PrintLoginRegisterRecordLine(Record);
				cout << endl;
			}
		
		cout << setw(8) << left << "" << "\n\t_____________________________________________";
		cout << "___________________________________________________\n" << endl;

	}
};

