/*
Luca Cristiano
Bryan Guan
Adian Walker
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <stdlib.h>

#include "POLYNOMIAL_H.h"
#include "POLY_TEST_H.h"

int main (){
    srand(time(NULL));

	PolynomialTest test;
	test.run();
	
	return EXIT_SUCCESS;
}
