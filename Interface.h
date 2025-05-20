/*! @file Interface.cpp
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
void Menu();
void PrintMenu();
void Showlist(vector<Function*> &f);//W
int InsertFun(vector<Function*> &f);//W
int DeleteFun(vector<Function*> &f);//W
int DeleteAll(vector<Function*> &f);//W
double SelectFun(vector<Function*> &f);//W
#endif