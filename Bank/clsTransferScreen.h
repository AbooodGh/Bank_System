#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsPerson.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"


class clsTransferScreen : protected clsScreen
{

private:

	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card : ";
		cout << "\n______________________\n";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc.Number  : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n______________________\n";
	}

	static string _ReadAccountNumber()
	{
		string AccountNmuber;
		cout << "\nPlease Enter Account Number to Transfer From : ";
		AccountNmuber = clsInputValidate::ReadString();
		while (!clsBankClient::IsClientExist(AccountNmuber))
		{
			cout << "\nAccount Number Is not Found , Choose another one ";
			AccountNmuber = clsInputValidate::ReadString();
		}
		return AccountNmuber;
	}

	static float ReadAmount(clsBankClient SourceClient)
	{
		float Amount;
		
		cout << "\nEnter Transfer Amount ? ";
		Amount = clsInputValidate::ReadNumber<float>();
		while (Amount > SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the Available Balance , Enter Another one ";
			Amount = clsInputValidate::ReadNumber<float>();
		}
		return Amount;
	}

public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\tTransfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());
		_PrintClient(DestinationClient);

		float Amount = ReadAmount(SourceClient);

		cout << "\nAre you sure you want to perform this operation ? ";
		char Answer = 'n';
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			if (SourceClient.Transfer(Amount,DestinationClient))
			{
				cout << "\nTransfer done Successfully\n";
			}
			else
			{
				cout << "\nTransfer Faild \n";
			}
		}

		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);
	}

};
 
