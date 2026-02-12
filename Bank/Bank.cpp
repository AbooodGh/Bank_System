
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"clsPerson.h"
#include<iomanip>
#include"clsBankClient.h"
#include"clsString.h"
#include"clsInputValidate.h"
#include "clsUtil.h"
#include"clsMainScreen.h"
#include"clsLoginScreen.h"

using namespace std;


void PrintFile(string FileName) {

	fstream MyFile;
	MyFile.open(FileName, ios::in);
	if (MyFile.is_open())
	{
		string line;
		while (getline(MyFile, line))
		{
			cout << line << endl;
		}
		MyFile.close();
	}
}




int main()
{
	while(true)
	{
		if (!clsLoginScreen::ShowLoginScreen())
		{
			break;
		}
	}

	

//	clsMainScreen::ShowMainMenue();

	//UpdateClient();

	//clsMainScreen::ShowMainMenue();

	//AddNewClient();

	//DeleteClient();
	//ShowClientsList();

	//clsBankClient Client1 = clsBankClient::Find("A101");
	//Client1.Print();

	//clsBankClient Client2 = clsBankClient::Find("A1011");
	//Client2.Print();

	//cout << endl << clsBankClient::IsClientEcist("A101") << endl;

//	PrintFile("Users.txt");

//	fstream MyFile;
//	MyFile.open("DoIt.txt", ios::out);
//	if (MyFile.is_open())
//	{
//		MyFile << "Adli#//#Haddad#//#Adli@gmail.com#//#8983883#//#User1#//#3456#//#-1";
//		MyFile.close();
//	
//	}


}

////////////