#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsCurrency.h"


class clsFindCurrencyScreen : protected clsScreen
{

private:

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card : \n";
		cout << "_________________________________\n";
		cout << "\nCountry		: " << Currency.Country();
		cout << "\nCode 		: " << Currency.CurrencyCode();
		cout << "\nName 		: " << Currency.CurrencyName();
		cout << "\nRate(1$)        : " << Currency.Rate();

		cout << "\n_________________________________\n";

	}

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Was NOt Found :-(\n";
		}
	}

public:
	
	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t	Find Currency Screen");

		cout << "\nFind By : [1] Code or [2] Country ? ";

		short Answer = 0;
		cin >> Answer;
		if (Answer == 1)
		{
			string CurrencyCode;
			cout << "\nPlease Enter Curreny Code : ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);

		}

		else 
		{
			string Country;
			cout << "\nPlease Enter Country Name : ";
			Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);

		}


	}



};

