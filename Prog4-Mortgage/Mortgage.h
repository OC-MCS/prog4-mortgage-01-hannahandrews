#pragma once
#include <string>

class Mortgage
{
private:
	int year;
	float loan;
	float intrest;
	float getterm();
public:
	Mortgage();
	Mortgage(float, float, int);
	float getpayment();
	float totalpaid();
};