// libraries
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <time.h>
#include <stdlib.h>

#include "POLYNOMIAL_H.h"
#include "POLY_TEST_H.h"

using namespace std;

Polynomial::Polynomial(int A[], int size) {
    data.resize(size);
    for (int i = 0; i < data.size(); i++){
        data[i] = A[i];
    }
    removerSelf();
}

Polynomial::Polynomial() {
    int size = rand() % 1001;
	data.resize(size);
    for (int i = 0; i < size; i++){
		data[i] = rand() % 2001 - 1000;
    }
}

Polynomial::Polynomial(string fileName){
    ifstream inFile;
    inFile.open(fileName.c_str());

    if (!inFile){
        cout << "File failed to open" << endl;
    }

    int sizePoly;
    inFile >> sizePoly;
	data.resize(sizePoly);
    data.assign(sizePoly, 0); // assigns vector 0 values so that missing values will have value of 0
    for (int i = 0; i < sizePoly; i++){
        inFile >> data[i];
    }

    inFile.close();
}


Polynomial Polynomial::operator+(const Polynomial & target){
    int iteration = 0;
    
    if (data.size() <= target.data.size()){
        
        iteration = data.size();
        
    }else{
        
        iteration = target.data.size();
        
    }
    
    vector<int> temp (iteration);
    
    for (int i = 0; i < iteration; i++){
        
        temp[i] = data[i] + target.data[i];
        
    }
    
	if (iteration < data.size()){
		
		for (int j = iteration; j < data.size(); j++){
			
			temp.push_back(data[j]);
			
		}
		
	}else if (iteration < target.data.size()){
		for (int j = iteration; j < data.size(); j++){
			
			temp.push_back(target.data[j]);
			
		}
	}
    
    Polynomial answer;
    answer.data = temp;
    
    return answer;
    
}

Polynomial Polynomial::operator-(const Polynomial&target){
    
    int iteration = 0;
    
    if (data.size() <= target.data.size()){
        
        iteration = data.size();
        
    }else{
        
        iteration = target.data.size();
        
    }
    
    vector<int> temp (iteration);
    
    for (int i = 0; i < iteration; i++){
        
        temp[i] = data[i] - target.data[i];
        
    }
    
	if (iteration < data.size()){
		
		for (int j = iteration; j < data.size(); j++){
			
			temp.push_back(data[j]);
			
		}
		
	}else if (iteration < target.data.size()){
		for (int j = iteration; j < data.size(); j++){
			
			temp.push_back(target.data[j]);
			
		}
	}
    
    Polynomial answer;
    answer.data = temp;
    
    return answer;
    
}

Polynomial Polynomial::operator*(const Polynomial & target){
    
    int tempExp = 0, tempCoef = 0;
    vector<int> temp (data.size() + target.data.size() - 1);
    
    for (int i = 0; i < data.size(); i++){
        for (int k = 0; k < target.data.size(); k++){
            
            tempExp = i + k;
            tempCoef = data[i] * target.data[k];
            
            temp[tempExp] = temp[tempExp] + tempCoef;
        }
    }
    
    Polynomial answer;
    answer.data = temp;
    
    return answer;
    
}

void Polynomial::removerTarget(Polynomial& target) {
    if (target.data[target.data.size() - 1] == 0){
        target.data.pop_back();
        removerTarget(target);
    }   
}

void Polynomial::removerSelf() {
    if (data[data.size() - 1] == 0){
        data.pop_back();
        removerSelf();
    }
   
}

bool Polynomial::operator==(Polynomial& target) {
    removerTarget(target); 
	removerSelf(); // ensures that polynomials with extra 0 coefficients are cut down
    for (int index = 0; index < target.data.size(); index++){
        if(target.data[index] != data[index])      
            return false;    
    }

    return true;
}

Polynomial Polynomial::derivative(){
    vector<int> deriv;
    deriv.resize(data.size() - 1);
    for (int der = 1; der < data.size(); der++){
        deriv[der - 1] = data[der] * der;
    }
	
    Polynomial answer;
    answer.data = deriv;
    
    return answer;
}

void Polynomial::print()
{
	for(int i = data.size() - 1; i >= 0; i--)
	{
		removerSelf();
		
		if (i == data.size() - 1){
			cout << data[i] << "x^" << i;
		}else{
			if (data [i] > 0){
				cout << " + "<< data[i] << "x^" << i;
			}else if (data [i] < 0){
				cout << " " << data[i] << "x^" << i;
			}
		}
	}
 }
