#include <iostream>
#include <fstream>
#include "src/Utils.hpp"

using namespace std;

int main()
{
	string inputfilename = "./data.txt";
	double S = 0;
	unsigned int n = 0;
	double* w = nullptr;
	double* r = nullptr;
	if(!importdata(inputfilename,S,n,w,r)){
		cerr << "errore nella lettura del file in input" <<endl;
	}
	double valorefinale = FinalValue(S,n,w,r);
	string outputfilename = "./results.txt";
	if(!exportresult(outputfilename,S,n,w,r,valorefinale)){
		cerr << "errore nella scrittura del file in output" << endl;
	}
	
	delete [] w;
	delete [] r;

    return 0;
}

