#include "Mortgage.h"
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//=========================================================
//Mortgage: This constructor sets the class values to 
//         default 0 values
//=========================================================
Mortgage::Mortgage()
{
	loan = 0;
	intrest = 0;
	year = 0;
}
//=========================================================
//Mortgage: This constructor sets the class values to the 
//         valid input the user enters
//=========================================================
Mortgage::Mortgage(float l, float i, int y)
{
	loan = l;
	intrest = i;
	year = y;
}
//=========================================================
//getterm: This func gets the term for the user's payments
//parameters: none
//return type: float
//  total: This is term for the user's payments
//=========================================================
float Mortgage::getterm()
{
	float term = pow((1 + (intrest / 12)), (12 * year));

	return term;
}
//=========================================================
//getpayment: This func gets the user's monthly payment
//parameters: none
//return type: float
//  total: This is the monthly amount the user will pay
//        throughout their pay period.
//=========================================================
float Mortgage::getpayment()
{
	float term = getterm();

	float payment = (loan * (intrest / 12) * term) / (term - 1);

	return payment;
}
//=========================================================
//totalpaid: This func gets the total that the user will pay
//parameters: none
//return type: float
//  total: This is the total amount the user will pay
//        throughout their pay period. 
//=========================================================
float Mortgage::totalpaid()
{
	float total;
	float payment = getpayment();
	total = payment * 12 * year;

	return total;
}
