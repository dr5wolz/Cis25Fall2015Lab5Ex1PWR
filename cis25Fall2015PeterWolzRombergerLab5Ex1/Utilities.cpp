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
#include "Fraction.cpp"

void mainMenu() {

	int menuChoice;
	FractionPeterW* firstFrac = nullptr;
	FractionPeterW* secondFrac = nullptr;
	FractionPeterW* returnedFrac = nullptr;
	int initalizeCheck = 0;

	do {
		cout << "\n********************\n"
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
			initalizeCheck = initializingMenu(&firstFrac, &secondFrac);
			break;
		case 2: cout << "\n  Adding Option --\n";
			if (initalizeCheck == 11) {
				addingMenu(firstFrac, secondFrac, &returnedFrac);
			} else {
				cout << "\n    Not a proper call as no Fractions are available!\n";
			}
			break;
		case 3: cout << "\n  Subtracting Option --\n";
			if (initalizeCheck == 11) {
				subtractingMenu(firstFrac, secondFrac, &returnedFrac);
			} else {
				cout << "\n    Not a proper call as no Fractions are available!\n";
			}
			break;
		case 4: cout << "\n  Multiplaying Option --\n";
			if (initalizeCheck == 11) {
				multiplyingMenu(firstFrac, secondFrac, &returnedFrac);
			} else {
				cout << "\n    Not a proper call as no Fractions are available!\n";
			}
			break;
		case 5: cout << "\n  Dividing Option --\n";
			if (initalizeCheck == 11) {
				dividingMenu(firstFrac, secondFrac, &returnedFrac);
			} else {
				cout << "\n    Not a proper call as no Fractions are available!\n";
			}
			break;
		case 6: cout << "\n  Printing Option --\n";
			if (returnedFrac == nullptr) {
				if (initalizeCheck =! 11) {
					cout << "\n    Not a proper call as no Fractions are available!\n";
				}
			} else {
				if (initalizeCheck == 11)
					printingMenu(firstFrac, secondFrac, &returnedFrac);
			}
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
	int initializeCheck1 = 0;
	int initializeCheck2 = 0;
	int num;
	int denom;

	do {
		cout << "\n    *******************************\n"
			<< "    *      INITIALIZING MENU      *\n"
			<< "    *                             *\n"
			<< "    * 1. Initialize left          *\n"
			<< "    * 2. Initialize right         *\n"
			<< "    * 3. Initialize both          *\n"
			<< "    * 4. Return to Previous MENU  *\n"
			<< "    *******************************\n";

		cout << "    Select an option (use integer value only): ";
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
			initializeCheck2 = 10;
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
			initializeCheck2 = 10;
			break;
		case 4:
			break;
		default:
			cout << "      WRONG OPTION!\n\n";
			break;
		}

	} while (menuChoice != 4);

	return (initializeCheck1 + initializeCheck2);
}

void init(FractionPeterW** fracIn, int numIn, int denomIn) {
	if (*fracIn == nullptr) {
		*fracIn = new FractionPeterW(numIn,denomIn);
		cout << "        calling FractionPeterW(int,int)\n"
			<< "        " << **fracIn;
	} else {
		cout << "        calling ~FractionPeterW()\n"
			<< "        " << **fracIn;
		delete *fracIn;
		*fracIn = new FractionPeterW(numIn, denomIn);
		cout << "        calling FractionPeterW(int,int)\n"
			<< "        " << **fracIn;
	}
}

void addingmenu(FractionPeterW* firstFrac,
	FractionPeterW* secondFrac, FractionPeterW** returnFrac) {
	int menuChoice;

	do {
		cout << "\n    *******************************\n"
			<< "    *         ADDING MENU         *\n"
			<< "    *                             *\n"
			<< "    * 1. add() - Member           *\n"
			<< "    * 2. add() - Stand Alown      *\n"
			<< "    * 3. operator+() - Member     *\n"
			<< "    * 4. Return to Previous MENU  *\n"
			<< "    *******************************\n";

		cout << "    Select an option (use integer value only): ";
		cin >> menuChoice;
		cout << endl;

		switch (menuChoice) {
		case 1:
			cout << "      Calling member add()";
			nulTest(returnFrac);
			*returnFrac = new FractionPeterW;
			**returnFrac = ((*firstFrac).add)(*secondFrac);
			break;
		case 2:
			cout << "      Calling stand alone add()";
			nulTest(returnFrac);
			*returnFrac = new FractionPeterW;
			**returnFrac = add(*firstFrac, *secondFrac);
			break;
		case 3:
			cout << "      Calling member operator+()";
			nulTest(returnFrac);
			*returnFrac = new FractionPeterW;
			**returnFrac = *firstFrac + *secondFrac;
			break;
		case 4:
			break;
		default:
			cout << "      WRONG OPTION!\n\n";
			break;
		}

	} while (menuChoice != 4);

}

void subtractingmenu(FractionPeterW* firstFrac,
	FractionPeterW* secondFrac, FractionPeterW** returnFrac) {
	int menuChoice;

	do {
		cout << "\n    *******************************\n"
			<< "    *      SUBTRACTING MENU       *\n"
			<< "    *                             *\n"
			<< "    * 1. subtract() - Member      *\n"
			<< "    * 2. subtract() - Stand Alown *\n"
			<< "    * 3. operator-() - Member     *\n"
			<< "    * 4. Return to Previous MENU  *\n"
			<< "    *******************************\n";

		cout << "    Select an option (use integer value only): ";
		cin >> menuChoice;
		cout << endl;

		switch (menuChoice) {
		case 1:
			cout << "      Calling member subtract()";
			nulTest(returnFrac);
			*returnFrac = new FractionPeterW;
			**returnFrac = (*firstFrac).subtract(*secondFrac);
			break;
		case 2:
			cout << "      Calling stand alone subtract()";
			nulTest(returnFrac);
			*returnFrac = new FractionPeterW;
			**returnFrac = subtract(*firstFrac, *secondFrac);
			break;
		case 3:
			cout << "      Calling member operator-()";
			nulTest(returnFrac);
			*returnFrac = new FractionPeterW;
			**returnFrac = *firstFrac - *secondFrac;
			break;
		case 4:
			break;
		default:
			cout << "      WRONG OPTION!\n\n";
			break;
		}

	} while (menuChoice != 4);

}

void multiplyingingmenu(FractionPeterW* firstFrac,
	FractionPeterW* secondFrac, FractionPeterW** returnFrac) {
	int menuChoice;

	do {
		cout << "\n    *******************************\n"
			<< "    *      MULTIPLYING MENU       *\n"
			<< "    *                             *\n"
			<< "    * 1. multiply() - Member      *\n"
			<< "    * 2. multiply() - Stand Alown *\n"
			<< "    * 3. operator*() - Member     *\n"
			<< "    * 4. Return to Previous MENU  *\n"
			<< "    *******************************\n";

		cout << "    Select an option (use integer value only): ";
		cin >> menuChoice;
		cout << endl;

		switch (menuChoice) {
		case 1:
			cout << "      Calling member multiply()";
			nulTest(returnFrac);
			*returnFrac = new FractionPeterW;
			**returnFrac = (*firstFrac).multiply(*secondFrac);
			break;
		case 2:
			cout << "      Calling stand alone multiply()";
			nulTest(returnFrac);
			*returnFrac = new FractionPeterW;
			**returnFrac = multiply(*firstFrac, *secondFrac);
			break;
		case 3:
			cout << "      Calling member operator*()";
			nulTest(returnFrac);
			*returnFrac = new FractionPeterW;
			**returnFrac = *firstFrac * *secondFrac;
			break;
		case 4:
			break;
		default:
			cout << "      WRONG OPTION!\n\n";
			break;
		}

	} while (menuChoice != 4);

}

void dividingmenu(FractionPeterW* firstFrac,
	FractionPeterW* secondFrac, FractionPeterW** returnFrac) {
	int menuChoice;

	do {
		cout << "\n    *******************************\n"
			<< "    *      DIVIDING MENU          *\n"
			<< "    *                             *\n"
			<< "    * 1. divide() - Member        *\n"
			<< "    * 2. divide() - Stand Alown   *\n"
			<< "    * 3. operator/() - Member     *\n"
			<< "    * 4. Return to Previous MENU  *\n"
			<< "    *******************************\n";

		cout << "    Select an option (use integer value only): ";
		cin >> menuChoice;
		cout << endl;

		switch (menuChoice) {
		case 1:
			cout << "      Calling member divide()";
			nulTest(returnFrac);
			*returnFrac = new FractionPeterW;
			**returnFrac = (*firstFrac).divide(*secondFrac);
			break;
		case 2:
			cout << "      Calling stand alone divide()";
			nulTest(returnFrac);
			*returnFrac = new FractionPeterW;
			**returnFrac = divide(*firstFrac, *secondFrac);
			break;
		case 3:
			cout << "      Calling member operator/()";
			nulTest(returnFrac);
			*returnFrac = new FractionPeterW;
			**returnFrac = *firstFrac / *secondFrac;
			break;
		case 4:
			break;
		default:
			cout << "      WRONG OPTION!\n\n";
			break;
		}

	} while (menuChoice != 4);

}

void printingmenu(FractionPeterW* firstFrac,
	FractionPeterW* secondFrac, FractionPeterW* returnFrac) {
	int menuChoice;

	do {
		cout << "\n    ********************************\n"
			<< "    *         PRINTING  MENU       *\n"
			<< "    * (leftOp, rightOp, result)    *\n"
			<< "    * 1. print() - Member          *\n"
			<< "    * 2. print() - Stand Alown     *\n"
			<< "    * 3. ostream << - Stand Alown  *\n"
			<< "    * 4. Return to Previous MENU   *\n"
			<< "    ********************************\n";

		cout << "    Select an option (use integer value only): ";
		cin >> menuChoice;
		cout << endl;

		switch (menuChoice) {
		case 1:
			cout << "      Calling member print()\n"
				<< "        leftOp:  ";
			(*firstFrac).print();
			cout << "\n        rightOp: ";
			(*secondFrac).print();
			cout << "\n        results: ";
			(*returnFrac).print();
			break;
		case 2:
			cout << "      Calling stand alone print()"
				<< "        leftOp:  ";
			print(*firstFrac);
			cout << "\n        rightOp: ";
			print(*secondFrac);
			cout << "\n        results: ";
			print(*returnFrac);
			break;
		case 3:
			cout << "      Calling stand alone operator <<";
			cout << "      Calling stand alone print()"
				<< "        leftOp:  " << *firstFrac
				<< "\n        rightOp: " << *secondFrac
				<< "\n        results: " << *returnFrac;
			break;
		case 4:
			break;
		default:
			cout << "      WRONG OPTION!\n\n";
			break;
		}

	} while (menuChoice != 4);

}

void nulTest(FractionPeterW** in) {
	if (*in != nullptr) {
		cout << "      Calling ~FractionPeterW\n"
			<< "      " << **in;
		delete *in;
	}
}

FractionPeterW add(FractionPeterW *firstFrac, FractionPeterW *secondFrac) {
	return ((*firstFrac).getnum() * (*secondFrac).getDenom() + (*firstFrac).getDenom() * (*secondFrac).getnum(),
		(*firstFrac).getDenom() * (*secondFrac).getDenom());
}

FractionPeterW subtract(FractionPeterW *firstFrac, FractionPeterW *secondFrac) {
	return ((*firstFrac).getnum() * (*secondFrac).getDenom() - (*firstFrac).getDenom() * (*secondFrac).getnum(),
		(*firstFrac).getDenom() * (*secondFrac).getDenom());
}

FractionPeterW divide(FractionPeterW *firstFrac, FractionPeterW *secondFrac) {
	return ((*firstFrac).getnum() * (*secondFrac).getDenom(), (*firstFrac).getDenom() * (*secondFrac).getnum());
}

FractionPeterW multiply(FractionPeterW *firstFrac, FractionPeterW *secondFrac) {
	return ((*firstFrac).getnum() * (*secondFrac).getnum(), (*firstFrac).getDenom() * (*secondFrac).getDenom());
}