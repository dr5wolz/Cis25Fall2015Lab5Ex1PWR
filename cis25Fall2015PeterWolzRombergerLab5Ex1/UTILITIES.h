/**
*Program Name: fraction.h
*Discussion:
*Writen by:    Peter Wolz-Romberger
*Date:         2015/
*/

using namespace std;
#ifndef UTILITIES_H
#define UTILITIES_H

void displayClassInfoPeterWolzRomberger(void);
void mainMenu(void);
int initializingMenu(FractionPeterW**, FractionPeterW**);
void addingMenu(FractionPeterW*, FractionPeterW*, FractionPeterW**);
void subtractingMenu(FractionPeterW*, FractionPeterW*, FractionPeterW**);
void multiplyingMenu(FractionPeterW*, FractionPeterW*, FractionPeterW**);
void dividingMenu(FractionPeterW*, FractionPeterW*, FractionPeterW**);
void printingMenu(FractionPeterW*, FractionPeterW*, FractionPeterW**);

void init(FractionPeterW**, int, int);
FractionPeterW add(const FractionPeterW&, const FractionPeterW&);
FractionPeterW subtract(const FractionPeterW&, const FractionPeterW&);
FractionPeterW multiply(const FractionPeterW&, const FractionPeterW&);
FractionPeterW divide(const FractionPeterW&, const FractionPeterW&);
void print(const FractionPeterW&);

void nulTest(FractionPeterW**);

#endif
