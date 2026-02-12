#pragma once
#include<iostream>
#include"clsScreen.h"
#include"clsPerson.h"
#include"clsInputValidate.h"
#include"clsUser.h"

class clsUpdateUserScreen : protected clsScreen
{

private:

	static void _ReadUserInfo(clsUser& User)
	{
		cout << "\nEnter FirstName : ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName : ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email : ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone : ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password : ";
		User.Password = clsInputValidate::ReadString();

		cout << "\nEnter Permission : ";
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

		cout << "\nDo you want to give full access ? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			return -1;
		}

		cout << "\nDo you want to give access to : \n";
		cout << "\nShow Client List ? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pListClients;
		}

		cout << "\nAdd New Client ? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pAddNewClient;
		}

		cout << "\nDelete Client ? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pDeleteClient;
		}

		cout << "\nUpdate Client ? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pUpdateClients;
		}

		cout << "\nFind Client ? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pFindClient;
		}

		cout << "\nTransactions ? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pTransactions;
		}

		cout << "\nManage Users ? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pManageUsers;
		}

		cout << "\nShow Login Register ? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pLoginRegister;
		}

		cout << "\nShow Currency Exchange ? y/n ? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			Permissions += clsUser::enPermissions::pCurrencyExchange;
		}

		return Permissions;
	}

public:

	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("\t    Update User Screen");

		string UserName = "";

		cout << "\nPlease Enter UserName : ";
		UserName = clsInputValidate::ReadString();
		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUserName Is Not Found , Choose another one : ";
			UserName = clsInputValidate::ReadString();
		}

		clsUser NewUser = clsUser::Find(UserName);

		_PrintUser(NewUser);

		cout << "\nAre you sure you want to update this User Y/N ? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			cout << "\n\nUpdate User Info : ";
			cout << "\n______________________\n";

			_ReadUserInfo(NewUser);
			
			clsUser::enSaveResults SaveResult;
			SaveResult = NewUser.Save();

			switch (SaveResult)
			{
			case clsUser::enSaveResults::svSucceeded:
			{
				cout << "\nUser Updated Successfully :-)\n";
				_PrintUser(NewUser);
			}
			case clsUser::enSaveResults::svFaildEmptyObject:
			{
				cout << "\nError User Was not saved ";
				break;
			}
			}

		}

	}

};

