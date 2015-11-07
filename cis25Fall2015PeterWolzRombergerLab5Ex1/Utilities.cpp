/**
*Program Name: Utilities.cpp
*Discussion:   Utilities
*Writen by:    Peter Wolz-Romberger
*Date:         2015/11/10
*/

#include "FRACTIONPETERW.h"
#include <iostream>
using namespace std;
#include "UTILITIES.h"

void mainMenu() {

	int menuChoice;
	int i, j;
	FractionPeterW* firstFrac = nullptr;
	FractionPeterW* secondFrac = nullptr;
	FractionPeterW* returnedFrac = nullptr;
	int intializeCheck = 0;

	do {
		cout << "********************\n"
			<< "*       MENU       *\n"
			<< "*                  *\n"
			<< "* 1. Initializing  *\n"
			<< "* 2. Adding        *\n"
			<< "* 3. Subtracting   *\n"
			<< "* 4. Multiplying   *\n"
			<< "* 5. Dividing      *\n"
			<< "* 6. Printing      *\n"
			<< "* 7. Quit          *\n"
			<< "********************\n";

		cout << "Select an option (use integer value only): ";
		cin >> menuChoice;
		cout << endl;

		switch (menuChoice) {
		case 1: cout << "\n  Initializing Option --\n";

			intializeCheck = initializingMenu(&firstFrac, &secondFrac);
			break;
		case 2: cout << "\n  Adding Option --\n";
			break;
		case 3: cout << "\n  Subtracting Option --\n";
			break;
		case 4: cout << "\n  Multiplaying Option --\n";
			break;
		case 5: cout << "\n  Dividing Option --\n";
			break;
		case 6: cout << "\n  Printing Option --\n";
			cout << "\n\n" << *firstFrac << "   " << *secondFrac;
			break;
		case 7: cout << "  Having Fun ...\n";
			break;
		default:
			cout << "WRONG OPTION!\n\n";
			break;
		}

	} while (menuChoice != 7);



}

void displayClassInfoPeterWolzRomberger() {

	cout << "CIS 25 - C++ Programming\n"
		<< "Laney College\n"
		<< "Peter Wolz-Romberger\n\n"
		<< "Assignment Information --\n"
		<< "  Assignment Number:  Lab 05,\n"
		<< "                      Exercise #1\n"
		<< "  Written by:         Peter Wolz-Romberger\n"
		<< "  Due Date:           2015/11/10\n\n" << endl;
}

int initializingMenu(FractionPeterW** frac1, FractionPeterW** frac2) {
	int menuChoice;
	int i, j;
	int initializeCheck1 = 0;
	int initializeCheck2 = 0;
	int num;
	int denom;

	do {
		cout << "    *******************************\n"
			<< "    *       MENU                  *\n"
			<< "    *                             *\n"
			<< "    * 1. Initialize left          *\n"
			<< "    * 2. Initialize right         *\n"
			<< "    * 1. Initialize both          *\n"
			<< "    * 4. Return to Previous Menu  *\n"
			<< "    *******************************\n";

		cout << "Select an option (use integer value only): ";
		cin >> menuChoice;
		cout << endl;

		switch (menuChoice) {
		case 1:
			cout << "\n      Enter the 2 intergers for the fraction"
				<< "\n      Numerator: ";
			cin >> num;
			cout << "      Denominator: ";
			cin >> denom;
			init(frac1, num, denom);
			initializeCheck1 = 1;
			break;
		case 2:
			cout << "\n      Enter the 2 intergers for the fraction"
				<< "\n      Numerator: ";
			cin >> num;
			cout << "      Denominator: ";
			cin >> denom;
			init(frac2, num, denom);
			initializeCheck2 = 1;
			break;
		case 3:
			cout << "\n      Enter the 2 intergers for the first fraction"
				<< "\n      Numerator: ";
			cin >> num;
			cout << "      Denominator: ";
			cin >> denom;
			init(frac1, num, denom);
			initializeCheck1 = 1;
			cout << "\n      Enter the 2 intergers for the second fraction"
				<< "\n      Numerator: ";
			cin >> num;
			cout << "      Denominator: ";
			cin >> denom;
			init(frac2, num, denom);
			initializeCheck2 = 1;
			break;
		case 4:
			break;
		default:
			cout << "WRONG OPTION!\n\n";
			break;
		}

	} while (menuChoice != 4);

	return (initializeCheck1 + initializeCheck2);
}

void init(FractionPeterW** fracIn, int numIn, int denomIn) {
	if (*fracIn == nullptr) {
		*fracIn = new FractionPeterW(numIn,denomIn);
		cout << "        calling FractionPeterW(int,int)\n"
			<< "        " << *fracIn;
	} else {
		cout << "        calling ~FractionPeterW()\n"
			<< "        " << **fracIn;
		delete fracIn;
		*fracIn = new FractionPeterW(numIn, denomIn);
		cout << "        calling FractionPeterW(int,int)\n"
			<< "        " << **fracIn;
	}
}