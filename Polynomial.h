#pragma once
using namespace std;

class Polynomial
{
private:
	int _degree;
	int _realDegree;
	double* _coff;
	static int _maxDegree;
	static int _count;

public:
	~Polynomial();
	Polynomial(int degree = 0);
	Polynomial(double* list, int degree);
	const void setDegree(const int degree);
	const void setCoeff(int deg, double num);
	double getCoeff(int index) const;
	static int getMaxDegree();
	int getDegree(bool tf)const;
	void print();
};
