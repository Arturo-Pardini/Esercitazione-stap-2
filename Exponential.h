/*! @file Exponential.h
	@brief A class for exponential functions 
	@author Arturo Pardini

	Details.
*/ 

#ifndef EXPONENTIAL_H
#define EXPONENTIAL_H

#include <iostream>
#include <cmath>
#include <cstring>
#include "CFunction.h"

using namespace std;

class Exponential: public Function{
	private:
		double b_coeff;
		double k_coeff;
		double c_coeff;
	public:
		
		/// @name CONSTRUCTORs and DESTRUCTOR 
		/// @{
		Exponential();
		Exponential(double b,double k,double c);
		Exponential(const Exponential& e);
		~Exponential();
		/// @}

		/// @name OPERATORS 
		/// @{
		Exponential& operator=(const Exponential& e);		
		bool operator==(const Exponential& e);
		/// @}


		void SetExponential(double b,double k,double c);
		double GetValue(double in);
	
	
		/// @name DEBUG  
		/// @{
		void Dump();
		/// @}
};
#endif