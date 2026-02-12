#pragma once
#include<iostream>
#include<iomanip>
#include"clsInputValidate.h"
#include"clsScreen.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyRateScreen.h"
#include"clsCurrencyCaculatorScreen.h"
class clsCurrencyExchangeMainScreen : protected clsScreen
{

private:
	enum enCurrenciesMainMenueOptions
	{
		eListCurrencies = 1 , eFindCurrency = 2 , 
		eUpdateCurrencyRate = 3 , eCurrencyCalculator = 4 ,
		eMainMenue = 5
	};

	static short _ReadMainMenueOption()
	{
		cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
		short Choice = clsInputValidate::ReadNumberBetween <short>(1, 5, "Enter Number between 1 to 5? ");
		return Choice;
	}

	static void _GoBackToCurrenciesMenue()
	{
		cout << "\n\nPress Any Key to go back to Currencies Menue ...\n";
		system("pause>0");
		ShowCurrenciesMenue();
	}

	static void _ShowCurrenciesLisScreen()
	{
		clsCurrenciesListScreen::ShowCurrenciesListScreen();
	}

	static void _ShowFindCurrenyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}

	static void _ShowUpdateCurrencyScreen()
	{
		clsUpdateCurrencyRateScreen::ShowUpdateCurrencyRateScreen();
	}

	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCaculatorScreen::ShowCurrencyCalculatorScreen();
	}

	static void _PerformCurrenciesMainMenueOptions(enCurrenciesMainMenueOptions CurrenciesMainMenueOptions)
	{
		switch (CurrenciesMainMenueOptions)
		{
		case clsCurrencyExchangeMainScreen::eListCurrencies:
		{
			system("cls");
			_ShowCurrenciesLisScreen();
			_GoBackToCurrenciesMenue();
			break;
		}
		case clsCurrencyExchangeMainScreen::eFindCurrency:
		{
			system("cls");
			_ShowFindCurrenyScreen();
			_GoBackToCurrenciesMenue();
			break;
		}
		case clsCurrencyExchangeMainScreen::eUpdateCurrencyRate:
		{
			system("cls");
			_ShowUpdateCurrencyScreen();
			_GoBackToCurrenciesMenue();
			break;
		}
		case clsCurrencyExchangeMainScreen::eCurrencyCalculator:
		{
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrenciesMenue();
			break;
			
		}
		case clsCurrencyExchangeMainScreen::eMainMenue:
		{
			break;
		}
		default:
			break;
		}
	}

public:

	static void ShowCurrenciesMenue()
	{

		if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchange))
		{
			return;
		}

		system("cls");
		_DrawScreenHeader("\tCurrency Exhange Main Screen");

		cout << setw(37) << left << "" << "=========================================\n";
		cout << setw(37) << left << "" << "\t\tCurrency Exhange Menue\n";
		cout << setw(37) << left << "" << "=========================================\n\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menue.\n\n";
		cout << setw(37) << left << "" << "=========================================\n";

		_PerformCurrenciesMainMenueOptions(enCurrenciesMainMenueOptions(_ReadMainMenueOption()));
	}
};

