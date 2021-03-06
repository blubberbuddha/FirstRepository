#include "stdafx.h"
#include <iostream>
#include <cctype>
#include "addieren.h"
#include "sub.h"
#include "mult.h"
#include "divide.h"
void calculate();
long double getNumber(bool& correct);
char getOperator();
using namespace std;

int main()
{
	bool cont{ true };
	char weiter{ ' ' };
	
	do
	{
		calculate();
		cout << "Erneute Eingabe? (Y/N)" << endl;
		cin >> weiter;
		if (weiter == 'N' || weiter == 'n')
		{
			cont = false;
		}
	}while (cont);

	return 0;
}

void calculate()
{
	long double zahl1{ 0 };
	long double zahl2{ 0 };
	long double erg{ 0 };
	char op{ ' ' };
	bool firstDigit = true;
	bool secondDigit = true;

	cout << "Eingabe Zahl1: ";
	while (firstDigit)
	{
		zahl1 = getNumber(firstDigit);
	}

	while (op == ' ')
	{
		op = getOperator();
	}
	
	cout << "Eingabe Zahl2: ";
	while (secondDigit)
	{
		zahl2 = getNumber(secondDigit);
	}

	switch (op)
	{
	case '+': erg = addieren(&zahl1,&zahl2); break;
	case '-': erg = subtract(&zahl1,&zahl2); break;
	case '*': erg = mult(&zahl1,&zahl2); break;
	case '/': erg = divide(&zahl1,&zahl2); break;
	default: cout << "Falscher operator!";
	}
	
	cout << "Rechnung: " << zahl1 << " " << op << " " << zahl2 << " = " << erg << "." << endl;

}

long double getNumber(bool& inputCorrect)
{
	long double num{ 0.0 };
	cin >> num;
	if (!cin) //Eingabe ist falsch!
	{
		inputCorrect = true;
		cout << "Wert ungültig!" << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
		cout << "Bitte erneute Eingabe!" << endl;
	}
	else {
		inputCorrect = false;
	}
	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail(), '\n');

	return num;
}
char getOperator()
{
	char op{ ' ' };

	cout << "Eingabe Operator: ";
	cin >> op;

	switch (op)
	{
	case '+': break;
	case '-': break;
	case '*': break;
	case '/': break;
	default: cout << "Falscher Operator!" << endl; op = ' ';
	}

	cin.clear();
	cin.ignore(cin.rdbuf()->in_avail());
	return op;
}