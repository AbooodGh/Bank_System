#pragma once
#include<iostream>
#include"clsMainScreen.h"
#include<iomanip>
#include"Global.h"



class clsLoginScreen : protected clsScreen
{
private:

	static bool _Login()
	{
		bool LoginFaild = false;
		short FaildloginCount = 0;

		string UserName, Password;
		do
		{
			if (LoginFaild)
			{
				FaildloginCount++;

				cout << "\nInvlaid UserName OR Password !";
				cout << "\nYou have " << (3 - FaildloginCount)
					 << " Trials to login .\n\n";
			}


			if (FaildloginCount == 3)
			{
				cout << "\nYour are loked after 3 faild trails \n\n";
				return false;
			}

			cout << "Enter UserName ? ";
			cin >> UserName;

			cout << "Enter Password ? ";
			cin >> Password;

			CurrentUser = clsUser::Find(UserName , Password);
			LoginFaild = CurrentUser.IsEmpty();

		} while (LoginFaild);

		CurrentUser.RegisterLogin();
		clsMainScreen::ShowMainMenue();
	}

public:
	
	static bool ShowLoginScreen()
	{
		system("cls");
		_DrawScreenHeader("\t\tLogin Screen");
		return _Login();
	}

};

