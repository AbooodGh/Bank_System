
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

////////////
