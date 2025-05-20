/*! @file Interface.h
	@brief Function of the Interface 
	@author Arturo Pardini

	Details.
*/ 

#ifndef INTERFACE_H
#define INTERFACE_H

#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>
#include "CFunction.h"
#include "Polynomial.h"
#include "Exponential.h"

/// @name FUNCTIONs
///@{
void Menu();
void PrintMenu();
void Showlist(vector<Function*> &f);
int InsertFun(vector<Function*> &f);
int DeleteFun(vector<Function*> &f);
int DeleteAll(vector<Function*> &f);
double SelectFun(vector<Function*> &f);
///@}


#endif