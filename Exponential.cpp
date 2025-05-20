/*! @file Polynomial.cpp
	@brief Implementation of Exponential class 
	@author Arturo Pardini

	Details.
*/ 


#include "Exponential.h"

/// @brief default constructor
Exponential::Exponential() {
	SetExponential(0,0,0);
}

/// @brief constructor
///	@param b base of exponential
///	@param k coefficent of base
/// @param c coefficent of exponential
Exponential::Exponential(double b,double k,double c) {
	SetExponential(b,k,c);
}

/// @brief destructor
Exponential::~Exponential() {
    
}

/// @brief copy constructor
Exponential::Exponential(const Exponential& e) {
	SetExponential(e.b_coeff,e.k_coeff,e.c_coeff);
	
}


/// @brief overload operator =
Exponential& Exponential::operator=(const Exponential& e) { 
	SetExponential(e.b_coeff,e.k_coeff,e.c_coeff);
	return *this;
}


/// @brief overload operator ==
bool Exponential::operator==(const Exponential& e) {
	
	if (b_coeff != e.b_coeff)
		return false;
	if (k_coeff != e.k_coeff)
		return false;
	if (c_coeff != e.c_coeff)
		return false;
	return true;
	
}

/// @brief sets the coefficients of the exponential 
///	@param b base of exponential
///	@param k coefficent of base
/// @param c coefficent of exponential
void Exponential::SetExponential(double b,double k,double c) {
	k_coeff=k;
	b_coeff=b;
	c_coeff=c;
	
	
}

/// @brief returns the value of the function, given an input 
///	@param in the input
///	@return the value of the function
double Exponential::GetValue(double in){
        
	double x = in*c_coeff;
	double y = pow(b_coeff,x);
	
		
	return k_coeff*y;
}







/// @brief gives the status of the object 
void Exponential::Dump() {

	int i;
	cout << "Your exponential:" << endl;
	if (k_coeff == 0 || b_coeff==0) {
		cout << b_coeff << endl;
		return;
	}
	else {
		cout << k_coeff << "(" << b_coeff << "^" << c_coeff << "x)"<< endl;
	}
	cout << endl;
}