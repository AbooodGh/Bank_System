#pragma once
#include<iostream>
#include<string>
#include"clsUser.h"
#include"Global.h"

using namespace std;


class clsScreen
{
protected:

	static void _DrawScreenHeader(string Title , string subTitle = "") 
	{
		cout << "\t\t\t\t     _________________________________";
		cout << "\n\n\t\t\t\t" << Title;
		if (subTitle != "")
		{
			cout << "\n\t\t\t\t" << subTitle;
		}
		cout << "\n\t\t\t\t     _________________________________\n\n";  	
		cout << "\t\t\t\t\tUser: " << CurrentUser.UserName << "\n";
		cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate())
			<< "\n\n";
	}

	static bool CheckAccessRights(clsUser::enPermissions Permissions)
	{
		if (!CurrentUser.CheckAccessPermission(Permissions))
		{
			cout << "\t\t\t\t\t______________________________________";
			cout << "\n\n\t\t\t\t\t  Access Denied! Contact Your Admin";
			cout << "\n\t\t\t\t\t______________________________________";
			return false;
		}
		else
		{
			return true;
		}
	}

};

