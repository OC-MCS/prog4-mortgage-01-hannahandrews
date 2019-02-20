//================================
// Hannah Andrews
//Spring Program 4
// Mortgage Payment
// 02-20-19
//================================

#include <iostream>
#include <iomanip>
#include <string>
#include "Mortgage.h"
using namespace std;

//These are my function prototypes.
bool validamount(float &amount, string input);
float getloan();
float getintrest();
int getyears();

int main()
{
	int years;
	float intrest, loan;

	//this is a validated loan amount from the user
	loan = getloan(); 
	//this is a validated intrest rate from the user
	intrest = getintrest();
	//this is a validated number of years from the user
	years = getyears();

	Mortgage mortgage(loan, intrest, years);
	//this assigns the validated info to morgage using a constructor

	cout << "Your monthly payment is $" << mortgage.getpayment();
	cout << " for a total amount paid of $" << mortgage.totalpaid();

	return 0;
}

//==========================================================
// validamount: This func tests if the user's input is valid
//parameters: float, string
//     amount: this is the numeric value of the input
//     input: this is the actual input the user entered
//return type: bool
//     valid: this returns true is the input is valid
//called by: getloan, getyears, getintrest
//==========================================================
bool validamount(float &amount, string input)
{
	//this is the value that says if the user input
	//is valid or not, initialized true
	bool valid = true;
	//this is a temp value to be assigned to amount if 
	//the input is valid
	float num = 0;

	//the try statement assigns the user input to num, num to account 
	//if possible
	try
	{
		num = stof(input);
		amount = num;
	}
	//this assigns valid to false if the input is invalid
	catch (const std::exception&)
	{
		valid = false;
	}
	if (amount < 0)
	{
		valid = false;
	}

	return valid;
}
//==========================================================
// getloan: This func gets the loan amount from the user
//parameters: none
//return type: float
//     loanamount: this returns the numeric loan amount
//called by: main
//==========================================================
float getloan()
{
	//this is my variable for what the user's loan amount
	string loan;
	//this variable initialized as false will remain false
	//if the user enters invalid data
	bool loanvalid = false;
	//this variable will be assigned the loan amount once
	//the users input is validated
	float loanamount = 0;

	//this loop will be entered initially and as long as
	//the user continues to enter invalid data 
	while (loanvalid == false)
	{
		cout << " What is the amount of the loan? ";
		cin >> loan;
		loanvalid = validamount(loanamount, loan);
		if (loanvalid == false)
		{
			cout << " This is an invalid loan amout.";
		}
	}
	
	return loanamount;
}
//==========================================================
// getintrest: This func gets the intrest amount from the user
//parameters: none
//return type: float
//     intrestamount: this returns the numeric intrest amount
//called by: main
//==========================================================
float getintrest()
{
	//this is the variable the user will enter for intrest rate
	string rate;
	//this variable initialized as false will remain false
	//if the user enters invalid data	
	bool ratevalid = false;
	float rateamount = 0;

	//this loop will be entered initially and as long as
	//the user continues to enter invalid data 
	while (ratevalid == false)
	{
		cout << " What is the intrest rate of the loan as a decimal? ";
		cin >> rate;
		ratevalid = validamount(rateamount, rate);
		if ((ratevalid == false) || (rateamount >= 1))
		{
			cout << " This is an invalid intrest rate.";
			ratevalid = false;
		}
	}


	return rateamount;
}
//==========================================================
// getyears: This func gets the loan amount from the user
//parameters: none
//return type: int
//     yearamount: this returns the numeric year amount
//called by:main
//==========================================================
int getyears()
{
	//this is the variable for the user's year input
	string years;
	//this is a temp value passed to the validation function
	//that will be assigned to yearamount once valid == true
	float temp;
	//this is the 
	int yearamount;
	//this variable initialized as false will remain false
	//if the user enters invalid data
	bool valid = false;

	//this loop will be entered initially and as long as
	//the user continues to enter invalid data 
	while (valid == false)
	{
		cout << " How many years will this loan be paid out over? ";
		cin >> years;
		valid = validamount(temp, years);
		if (valid == false)
		{
			cout << " This is an invalid input. ";
		}
	}

	yearamount = static_cast<int>(temp);

	return yearamount;
}