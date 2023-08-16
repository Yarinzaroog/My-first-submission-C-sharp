#include "Rational.h"
#include <iostream>
using namespace std;

void Rational::print()
{
	this->_numerator.print();
	cout << "---------------" << endl;
	if (this->_denominator.getDegree(true) == 0)
		cout << "Polinomial = 1 " << endl;
	else
		this->_denominator.print();
}
Polynomial& Rational::getNom()
{
	return this->_numerator;
}
Polynomial& Rational::getDenom()
{
	return this->_denominator;
}