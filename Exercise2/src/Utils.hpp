#pragma once
#include <iostream>

using namespace std;

bool importdata(const string& inputfilename,
				double& S,
				unsigned int& n,
				double*& w,
				double*& r);
				
double FinalValue(const double& S,
				const unsigned int& n,
				const double* const& w,
				const double* const& r);
				
bool exportresult(const string& outputfilename,
				const double& S,
				const unsigned int& n,
				const double* const& w,
				const double* const& r,
				const double& finalvalue);
				
				