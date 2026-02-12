#pragma once
#include<iostream>
#include"clsCurrency.h"
#include"clsScreen.h"
#include"clsInputValidate.h"


class clsUpdateCurrencyRateScreen : protected clsScreen
{

private:

	static float _ReadRate()
	{
		cout << "Enter New Rate : ";
		float NewRate = 0;

		NewRate = clsInputValidate::ReadNumber <float>();
		return NewRate;
	}

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

public:

	static void ShowUpdateCurrencyRateScreen()
	{
		string CurrencyCode = "";

		cout << "\nPlease Enter Currency Code : ";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency Is Not Found , choose another one : ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);

		cout << "\nAre you sure you want to update the rate Y/N ? ";

		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			cout << "\n\nUpdate Currency Rate : ";
			cout << "\n________________________\n";

			Currency.UpdateRate(_ReadRate());

			cout << "\nCurrency Rate Updated Successfully :-)\n";
			_PrintCurrency(Currency);

		}
	}

};

