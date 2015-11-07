/**
 *Program Name: Fraction.cpp
 *Discussion:   Fractions
 *Writen by:    Peter Wolz-Romberger
 *Date:         2015/11/10
 */

#include "FRACTIONPETERW.h"
#include <iostream>
using namespace std;

FractionPeterW::FractionPeterW() : num(0), denom(1) {
}

FractionPeterW::FractionPeterW(int n) : num(n), denom(1) {
}

FractionPeterW::FractionPeterW(const FractionPeterW &n) : num(n.num), denom(n.denom) {\
	reduce(*this);
}

FractionPeterW::FractionPeterW(int n, int d) : num(n), denom(d) {\
	reduce(*this);
}

void FractionPeterW::print() {
	cout << num << " / " << denom;
}

void FractionPeterW::setDenom(int d) {
	denom = d;
}

void FractionPeterW::setNum(int n) {
	num = n;
}

int FractionPeterW::getDenom() const {
	return denom;
}

int FractionPeterW::getNum() const {
	return num;
}

FractionPeterW::~FractionPeterW() {

}

void FractionPeterW::reduce(FractionPeterW& in) {
	int i;
	for (i = 2; i <= denom; i++) {
		if (denom % i == 0) {
			if (num % i == 0) {
				num /= i;
				denom /= i;
				i--;
			}
		}
	}
}

ostream& operator<<(ostream& os, const FractionPeterW& in) {
	os << in.num << "/" << in.denom;
	return os;
}

FractionPeterW FractionPeterW::operator-(const FractionPeterW& in) {
	return FractionPeterW(num*in.denom-in.num*denom,denom*in.denom);
}

FractionPeterW FractionPeterW::operator+(const FractionPeterW& in) {
	return FractionPeterW(num*in.denom+in.num*denom, in.denom*denom);
}

FractionPeterW FractionPeterW::operator*(const FractionPeterW& in) {
	return FractionPeterW(num*in.num, denom*in.denom);
}

FractionPeterW FractionPeterW::operator/(const FractionPeterW& in) {
	return FractionPeterW(num*in.denom, denom*in.num);
}

FractionPeterW FractionPeterW::operator=(const FractionPeterW& in) {
	num = in.num;
	denom = in.denom;
	return FractionPeterW(in.num, in.denom);
}

FractionPeterW FractionPeterW::add(const FractionPeterW& in) {
	return FractionPeterW(num*in.denom + in.num*denom, in.denom*denom);
}

FractionPeterW FractionPeterW::subtract(const FractionPeterW& in) {
	return FractionPeterW(num*in.denom - in.num*denom, denom*in.denom);
}

FractionPeterW FractionPeterW::divide(const FractionPeterW& in) {
	return FractionPeterW(num*in.denom, denom*in.num);
}

FractionPeterW FractionPeterW::multiply(const FractionPeterW& in) {
	return FractionPeterW(num*in.num, denom*in.denom);
}
