#pragma once
#include "Polynomial.h"

class Rational
{
private:
	Polynomial _numerator;
	Polynomial _denominator;

public:
	~Rational() {};
	Rational() {};
	Rational(Polynomial p1, Polynomial p2) :_numerator(p1), _denominator(p2) {};
	void print();
	Polynomial& getNom();
	Polynomial& getDenom();
};

