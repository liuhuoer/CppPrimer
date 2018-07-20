#ifndef EX7_57_H
#define EX7_57_H

#include <string>

class Account
{
public:
	static double rate(){return interestRate;}
	static void rate(double newRate){interestRate=newRate;}
	void calculate(){amount+=amount*interestRate;}

private:
	std::string owner;
	double amount;
	static double interestRate;
	static constexpr double todayRate=42.42;
	static double initRate(){return todayRate;}
};

double Account::interestRate=initRate();

#endif
