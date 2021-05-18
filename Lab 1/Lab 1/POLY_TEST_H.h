#ifndef POLY_TEST_H
#define POLY_TEST_H

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <cassert>
#include "POLYNOMIAL_H.h"


using namespace std;
class PolynomialTest
{
	vector<int>test_coeff;
		int coeff[];
		int coeff_[];
		int coeff1[]; 
		int coeff2[];
		int derivative[]; 
		int multiply[];
		int added[];
		int subtract[];
		int special[];
	
	public:	
	//void set_up();
	void test_constructor();
	void test_file_read();
	void test_operator_overload();
	void special_cases();
	void test_derivative();
	void test_print();
	void run();
};

#endif
