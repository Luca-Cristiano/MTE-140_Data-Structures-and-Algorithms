#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include "POLY_TEST_H.h"

using namespace std;

class Polynomial
{
	private:
		vector<int> data;
	public:
		Polynomial(int A[],int size);
		Polynomial();
		Polynomial(string fileName);
		bool operator==(Polynomial& target);
		void print();
		Polynomial operator+(const Polynomial& target);
		Polynomial operator-(const Polynomial& target);
		Polynomial operator*(const Polynomial& target);
		void removerTarget(Polynomial& target);
		void removerSelf();
		Polynomial derivative();
		friend class PolynomialTest;
};

#endif
