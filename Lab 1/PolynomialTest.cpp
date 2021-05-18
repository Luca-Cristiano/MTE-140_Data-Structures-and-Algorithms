#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <cassert>

#include "POLY_TEST_H.h"

using namespace std;
				
	void PolynomialTest::test_constructor()
	{
		int coeff[4]={1, 2, 3, 4};
		test_coeff.push_back(1);
		test_coeff.push_back(2);
		test_coeff.push_back(3);
		test_coeff.push_back(4);
		
		Polynomial p1 = Polynomial (coeff,4);
		
		Polynomial p30;
		
		p30.print();
		cout << endl;
		
		assert(test_coeff == p1.data);
		cout<<"Constructor test is successful"<<endl;	
	}
	void PolynomialTest::test_file_read()
	{
		int coeff[4]={1, 2, 3, 4};
		Polynomial p11 = Polynomial (coeff, 4);
		Polynomial p12 = Polynomial ("testfile.txt");
		
		assert(p11 == p12);
		cout<<"File read is successful"<<endl;
	}
	
	void PolynomialTest::test_operator_overload()
	{
		int coeff[4]={1, 2, 3, 4};
		int coeff_[6] = {1,2,3,4,0,0};
		int coeff1[1] = {4};
		int coeff2[2] = {1,2};
		int multiply[2] = {4,8};
		int added[4] = {2,4,6,8};
		int subtract[4]={0,0,0,0};
		int coeff3[4] = {1,4, 4, 2};
		int coeff4[1] = {10};
		int coeff5[2] = {1,-2};
		int coeff6[4] = {1, 2, 7, 4};
		int subtract2[4] = {-9,2,7,4};
		int multiply2[3] = {1,0,-4};
		int added2 [4] = {2, 6, 7, 6};
		
		Polynomial p2 = Polynomial (coeff, 4);
		Polynomial p3 = Polynomial (coeff_, 6);
		Polynomial p4 = Polynomial (added,4);
		Polynomial p5 = Polynomial (subtract, 4);
		Polynomial p6 = Polynomial (coeff1, 1);
		Polynomial p7 = Polynomial (coeff2, 2);
		Polynomial p8 = Polynomial (multiply,2);
		Polynomial p9 = Polynomial (coeff3, 4);
		Polynomial p18 = Polynomial (coeff6, 4);
		Polynomial p19 = Polynomial (coeff4, 1);
		Polynomial p20 = Polynomial (subtract2, 4);
		Polynomial p21 = Polynomial (coeff5, 2);
		Polynomial p22 = Polynomial (multiply2, 3);
		Polynomial p23 = Polynomial (added2, 4);
	
		
		assert(p2 == p3);
		cout<<"Operator equals is successful."<<endl;
		
		assert(!(p2 == p6));
		cout<<"Operator equals is successful."<<endl;
		
		assert(p2 + p3 == p4);
		assert(p9 + p2 == p23);
		cout<<"Operator add is successful."<<endl;
		
		assert(p18 - p19 == p20);
		assert(p2 - p3 == p5);
		cout<<"Operator subtract is successful"<<endl;
		
		
		assert(p6*p7 == p8);
		assert(p21*p7 == p22);
		cout<<"Operator multiply is successful"<<endl;
		
		Polynomial p_Extra = Polynomial ("testfile_2.txt");
		Polynomial p_Less = Polynomial ("testfile_3.txt");
		
		int ex[1] = {2};
		int less[4]={1,2,3,0};
		
		Polynomial p16 = Polynomial (ex, 1);
		Polynomial p17 = Polynomial (less, 4);
		
		assert(p16 == p_Extra);
		cout << "Extra value, file read is successful"<<endl;
		
		assert(p17 == p_Less);
		cout << "Less value, file read is successful"<<endl;
	}
	
	void PolynomialTest::special_cases(){
		int coeff[4]={1, 2, 3, 4};
		int subtract[5]={0,0,0,0,0};
		int special[5] = {0,0,0,0,0};
		
		Polynomial p13 = Polynomial (subtract, 4);
		Polynomial p14 = Polynomial (special, 5);
		Polynomial p15 = Polynomial (coeff, 5);
		
		assert(p13 == p14);
		cout<<"Operator equals is successful."<<endl;
		
		assert(p14 + p15 == p14);
		cout<<"Operator add is successful."<<endl;
		
		assert(p14 - p15 == p14);
		cout<<"Operator subtract is successful"<<endl;
		
		assert(p14*p15 == p14);
		cout<<"Operator multiply is successful"<<endl;
	}
	
	void PolynomialTest::test_derivative()
	{
		int coeff[4]={1, 2, 3, 4};
		int derivative[3] = {2,6,12}; 
		
		Polynomial p9 = Polynomial (coeff, 4);
		Polynomial p10 = Polynomial (derivative, 3);
		
		assert(p9.derivative() == p10);
		cout<<"Derivative is successful"<<endl;
	}
	
	void PolynomialTest::test_print()
	{
		int test_poly[4] = {0,-5,1,4};
		int test_poly2[3] = {-5,0,4};
		int test_poly3[5] = {0,-5,1,0, 3};
		Polynomial p_Print1 = Polynomial (test_poly, 4);
		Polynomial p_Print2 = Polynomial (test_poly2, 3);
		Polynomial p_Print3 = Polynomial (test_poly3, 5);
		
		p_Print1.print();
		cout <<"\n";
	
		p_Print2.print();
		cout<<"\n";
		
		p_Print3.print();
		cout<<"\n";
		cout<<"Print successfully"<<endl;
	}
	
	void PolynomialTest::run()
	{
		test_constructor();
		test_file_read();
		test_print();
		test_operator_overload();
		test_derivative();
		special_cases();
	}
