#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"clsPerson.h"
#include"clsString.h"
#include"clsDate.h"
#include"Global.h"



class clsBankClient : public clsPerson
{

private:
	enum enMode { EmptyMode = 0 , UpdateMode = 1  , AddNewMode = 2};
	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _MarkedForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Seperator = "#//#")
	{
		vector <string> vClientData;
		vClientData = clsString::Split(Line, Seperator);

		return clsBankClient(enMode::UpdateMode, vClientData[0], vClientData[1],
			vClientData[2], vClientData[3], vClientData[4], vClientData[5],
			stod(vClientData[6]));
	}

	static string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string stClientRecord = "";
		stClientRecord += Client.FirstName + Seperator;
		stClientRecord += Client.LastName + Seperator;
		stClientRecord += Client.Email + Seperator;
		stClientRecord += Client.Phone + Seperator;
		stClientRecord += Client.AccountNumber() + Seperator;
		stClientRecord += Client.PinCode + Seperator;
		stClientRecord += to_string(Client.AccountBalance);

		return stClientRecord;

	}

	static clsBankClient _GetEmptyClientObject() {
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static  vector <clsBankClient> _LoadClientsDataFromFile() {

		vector <clsBankClient> vClients;
		fstream Myfile;
		Myfile.open("Clients.txt", ios::in);

		if (Myfile.is_open())
		{
			string Line;

			while (getline(Myfile,Line))
			{

				clsBankClient Client = _ConvertLineToClientObject(Line);
				vClients.push_back(Client);

			}
			Myfile.close();
		}
		return vClients;
	}

	static void _SaveCleintDataToFile(vector <clsBankClient> vClients)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{
			for(clsBankClient C : vClients)
			{
				if (C.MarkedForDeleted() == false)
				{
					DataLine = _ConvertClientObjectToLine(C);
					MyFile << DataLine << endl;
				}
				

			}
			MyFile.close();
		}

	}


	void _Update()
	{
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vClients)
		{
			if (C.AccountNumber() == AccountNumber())
			{
				C = *this;
				break;
			}
		}
		_SaveCleintDataToFile(_vClients);
	}

	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}

	void _AddDataLineToFile(string  stDataLine)
	{
		fstream MyFile;
		MyFile.open("Clients.txt", ios::out | ios::app);
		
		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
			
			MyFile.close();
		}
	}

	string _PrepareTransferLogRecord(float Amount, clsBankClient DestinationClient,
		string UserName, string Seperator = "#//#")
	{
		string TransferLogRecord = "";
		TransferLogRecord += clsDate::GetSystemDateTimeString() + Seperator;
		TransferLogRecord += AccountNumber() + Seperator;
		TransferLogRecord += DestinationClient.AccountNumber() + Seperator;
		TransferLogRecord += to_string(int(Amount)) + Seperator;
		TransferLogRecord += to_string(int(AccountBalance)) + Seperator;
		TransferLogRecord += to_string(int(DestinationClient.AccountBalance)) + Seperator;
		TransferLogRecord += UserName;
		return TransferLogRecord;
	}
	
	void _RegisterTransferLog(float Amount, clsBankClient DestinationClient, string UserName)
	{
		string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient, UserName);

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << stDataLine << endl;
		}
		MyFile.close();
	}

	struct stTransferLogRecord;
	static stTransferLogRecord _ConvertTransferLogLineToRecord(string Line , string Seperator = "#//#")
	{
		stTransferLogRecord TransferLogRecord;
		vector <string> vTransferLogRecord = clsString::Split(Line, Seperator);

		TransferLogRecord.DateTime = vTransferLogRecord[0];
		TransferLogRecord.SourceAccountNumber = vTransferLogRecord[1];
		TransferLogRecord.DestinationAccountNumber = vTransferLogRecord[2];
		TransferLogRecord.Amount = stoi(vTransferLogRecord[3]);
		TransferLogRecord.srcBalanceAfter = stoi(vTransferLogRecord[4]);
		TransferLogRecord.destBalanceAfter = stoi(vTransferLogRecord[5]);
		TransferLogRecord.UserName = vTransferLogRecord[6];
		
		return TransferLogRecord;
	}

	
public:

	struct stTransferLogRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		string UserName;
		float Amount;
		float srcBalanceAfter;
		float destBalanceAfter;
	};


	clsBankClient(enMode Mode, string FirstName, string LastName,
		string Email, string Phone , string AccountNumber , string PinCode ,
		float AccountBalance) :
		clsPerson(FirstName, LastName, Email, Phone) {

		_Mode = Mode;
		_AccountBalance = AccountBalance;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
	}

	bool IsEmpty() {
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber() {
		return _AccountNumber;
	}

	bool MarkedForDeleted() {
		return _MarkedForDelete;
	}

	void SetPinCode(string PinCode) {
		_PinCode = PinCode;
	}

	string GetPinCode() { 
		return _PinCode;
	}

	_declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance) {
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance() {
		return _AccountBalance;
	}

	_declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	/*
	void Print() {
		
		cout << "\nClient Card : ";
		cout << "\n____________________________";
		cout << "\nFirstName   : " << FirstName;
		cout << "\nLastName    : " << LastName;
		cout << "\nFull Name   : " << FullName();
		cout << "\nEmail       : " << Email;
		cout << "\nPhone       : " << Phone;
		cout << "\nAcc.Number  : " << _AccountNumber;
		cout << "\nPassword    : " << _PinCode;
		cout << "\nBalance     : " << _AccountBalance;
		cout << "\n____________________________\n";
	}*/

	static clsBankClient Find(string AccountNumber) {

		//vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line)) {
				
				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
				//vClients.push_back(Client);
			}
			MyFile.close();
		}
		
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber , string PinCode)
	{

		//vector <clsBankClient> vClients;
		fstream MyFile;
		MyFile.open("Clients.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line)) 
			{

				clsBankClient Client = _ConvertLineToClientObject(Line);
				if (Client.AccountNumber() == AccountNumber 
					&& Client.PinCode == PinCode )
				{
					MyFile.close();
					return Client;
				}
				//vClients.push_back(Client);
			}
			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber) {

		clsBankClient  Client1 = clsBankClient::Find(AccountNumber);
		return (!Client1.IsEmpty());
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);

	}

	enum enSaveResults { svFaildEmptyObject = 0 , svSucceeded = 1 , svFaildAccountNumberExists = 2};

	enSaveResults Save()
	{
		 
		switch (_Mode)
		{
		case enMode::EmptyMode : 
		{
			return enSaveResults::svFaildEmptyObject;
		}
		
		case enMode::UpdateMode:
		{

			_Update();
			return enSaveResults::svSucceeded;
			break;
		}

		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildAccountNumberExists;
			}
			else
			{
				_AddNew();

				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
			}

		}
		}
	}

	bool Delete() 
	{
		
		vector <clsBankClient> _vClients;
		_vClients = _LoadClientsDataFromFile();
		
		for (clsBankClient & C : _vClients )
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDelete = true;
				break;
			}
		}
		_SaveCleintDataToFile(_vClients);
		*this = _GetEmptyClientObject();

		return true;
	}

	static vector <clsBankClient> GetClientsList() 
	{
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances()
	{
		vector <clsBankClient> vClients = clsBankClient::GetClientsList();

		double TotalBalances = 0;

		for (clsBankClient Client : vClients )
		{
			TotalBalances += Client.AccountBalance;
		}

		return TotalBalances;

	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool Withdraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();
		}
		//return true;
	}



	bool Transfer(float Amount, clsBankClient& DestinationClient)
	{
		if (Amount > AccountBalance)
		{
			return false;
		}

		Withdraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient, CurrentUser.UserName);
		return true;
	}

	static vector <stTransferLogRecord> GetTransferLogList()
	{
		vector <stTransferLogRecord> vTransferLogRecord;

		fstream MyFile;
		MyFile.open("TransferLog.txt", ios::in);

		if (MyFile.is_open())
		{
			string Line;
			stTransferLogRecord TransferLogRecord;

			while (getline(MyFile,Line))
			{
				TransferLogRecord = _ConvertTransferLogLineToRecord(Line);
				vTransferLogRecord.push_back(TransferLogRecord);
			}
			MyFile.close();
		}

		return vTransferLogRecord;
	}

};

