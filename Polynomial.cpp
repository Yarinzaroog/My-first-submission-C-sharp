#include "Polynomial.h"
using namespace std;
#include <iostream>

int Polynomial::_maxDegree = 0;
int Polynomial::_count = 0;

Polynomial::~Polynomial()
{
	_count--;
}
Polynomial::Polynomial(int degree)
{
	_coff = new double[degree + 1] {0};
	setDegree(degree);
	_realDegree = 0;
	_count++;
}
Polynomial::Polynomial(double* coffList, int  degree)
{
	int i;
	_coff = new double[degree + 1] {0};
	setDegree(degree);
	_realDegree = 0;
	for (i = 0; i <= degree; i++)
	{
		setCoeff(i, coffList[i]);
	}
	_count++;
}
const void Polynomial::setDegree(const int degree)
{
	_degree = degree;
}
const void Polynomial::setCoeff(int deg, double num)
{

	_maxDegree = ((num != 0) && (_maxDegree < deg)) ? (deg) : _maxDegree;
	_coff[deg] = num;
	if (num != 0)
	{
		_realDegree = (deg > _realDegree) ? (deg) : _realDegree;
	}
	if (num == 0 && deg == _realDegree)
		while (_realDegree)
		{
			if (_coff[_realDegree + 1] != 0)
			{
				return;
			}
			_realDegree--;
		}
}
double Polynomial::getCoeff(int index) const
{
	try
	{
		if (index > this->getDegree(false) || index < 0)
			throw - 12345.5;
		return _coff[index];
	}
	catch (const double error)
	{
		return error;
	}
}
int Polynomial::getMaxDegree()
{
	return _maxDegree;
}
int Polynomial::getDegree(bool tf) const
{
	if (tf)
		return _realDegree;
	return _degree;
}
void Polynomial::print()
{
	int i;
	cout << "polynomial = ";
	if (_degree == 0) {
		cout << "0" << endl;
		return;
	}
	for (i = 0; i <= _realDegree; i++)
	{
		if (_coff[i] - (int)_coff[i] > 0)
			cout << _coff[i];
		else
		{
			cout << (int)_coff[i];
		}
		if (i > 0)
			cout << "X^" << i;

		if (i + 1 <= _realDegree && _coff[i + 1] >= 0)
			cout << "+";
	}
	cout << endl;
}







