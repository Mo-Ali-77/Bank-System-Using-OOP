#pragma once
#include<iostream>
#include "clsDate.h"

class clsInputValidate
{
public:

	static string ReadString(string Message)
	{
		string S = "";
		cout << Message;
		getline(cin >> ws, S);
		return S;
	}

	static string ReadString()
	{
		string S = "";
		getline(cin >> ws, S);
		return S;
	}

	static char ReadChar(string Message)
	{
		char C;
		cout << Message;
		cin >> C;
		return C;
	}

	static char ReadChar()
	{
		char C;
		cin >> C;
		return C;
	}

	static bool IsNumberBetween(int Number, int From, int To)
	{
		return Number >= From&& Number <= To;
	}

	static bool IsNumberBetween(double Number, double From, double To)
	{
		return Number >= From && Number <= To;
	}

	static bool IsNumberBetween(float Number, float From, float To)
	{
		return Number >= From && Number <= To;
	}

	static bool IsNumberBetween(short Number, short From, short To)
	{
		return Number >= From && Number <= To;
	}

	static bool IsDateBetween(clsDate Date, clsDate From, clsDate To)
	{
		if (clsDate::IsDate1AfterDate2(From, To))
			clsDate::SwapDates(From, To);
		
		return (clsDate::IsDate1AfterDate2(Date, From) || clsDate::IsDate1EqualDate2(Date,From)) 
			 && (clsDate::IsDate1BeforeDate2(Date, To) || clsDate::IsDate1EqualDate2(Date,To));
	}

	static short ReadShortNumber(string ErrorMessage = "Invalid Short Number, Enter again : ")
	{
		short Num;

		while (!(cin >> Num))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage << "\n";
		}

		return Num;
	}
	
	static short ReadShortNumberBetween(short From, short To, string ErrorMessage)
	{
		short Num = ReadShortNumber();

		while (!IsNumberBetween(Num, From, To))
		{
			cout << ErrorMessage;
			cin >> Num;
		}

		return Num;
	}

	static int ReadIntNumber(string ErrorMessage = "Invalid Int Number, Enter again : ")
	{
		int Num;

		while (!(cin >> Num))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage << "\n";
		}

		return Num;
	}

	static int ReadIntNumberBetween(int From, int To, string ErrorMessage)
	{
		int Num = ReadIntNumber();

		while (!IsNumberBetween(Num, From, To))
		{
			cout << ErrorMessage;
			cin >> Num;
		}

		return Num;
	}

	static float ReadFloatNumber(string ErrorMessage = "Invalid Float Number, Enter again : ")
	{
		float Num;

		while (!(cin >> Num))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage << "\n";
		}

		return Num;
	}

	static int ReadFloatNumberBetween(float From, float To, string ErrorMessage)
	{
		float Num = ReadIntNumber();

		while (!IsNumberBetween(Num, From, To))
		{
			cout << ErrorMessage;
			cin >> Num;
		}

		return Num;
	}

	static double ReadDbNumber(string ErrorMessage = "Invalid Double Number, Enter again : ")
	{
		double Num;

		while (!(cin >> Num))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << ErrorMessage << "\n";
		}

		return Num;
	}

	static double ReadDbNumberBetween(double From, double To, string ErrorMessage)
	{
		double Num = ReadDbNumber();

		while (!IsNumberBetween(Num, From, To))
		{
			cout << ErrorMessage;
			cin >> Num;
		}

		return Num;
	}

	static bool IsValidDate(clsDate Date)
	{
		return clsDate::IsValidDate(Date);
	}

};

