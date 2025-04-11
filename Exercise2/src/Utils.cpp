#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "string"
#include "iomanip"

using namespace std;

bool importdata(const string& inputfilename,
				double& S,
				unsigned int& n,
				double*& w,
				double*& r)
				{
					ifstream file(inputfilename);
					if (file.fail()){
						return false;
					}
					// leggo valore S scartando 'S'
					string s_string;
					getline(file,s_string,';');
					file >> S;
					// leggo valore n scartando 'n'
					string n_string;
					getline(file,n_string,';');
					file >> n;
					// scarto stringa 'w;r'
					string tmp1;
					string tmp2;
					getline(file,tmp1,';');
					file >> tmp2;
					// salvo valori di w e r 
					w = new double[n];
					r = new double[n];
					for (unsigned int i = 0; i<n; i++){
						string wr;
						getline(file,wr,';');
						w[i] = stod(wr); //stod per convertire string in double
						file >> r[i];
					}
					file.close();
					return true;
				}
				
double FinalValue(const double& S,
				const unsigned int& n,
				const double* const& w,
				const double* const& r)
				{
					double finalvalue = 0;
					for (unsigned int i = 0; i<n; i++)
						finalvalue += (w[i]*S) * (1+r[i]);
					return finalvalue;
					
				}
				
				
bool exportresult(const string& outputfilename,
				const double& S,
				const unsigned int& n,
				const double* const& w,
				const double* const& r,
				const double& finalvalue)
				{
					ofstream file(outputfilename);
					if(file.fail()){
						return false;
					}
					file << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
					file << "w = [ ";
					for(unsigned int i = 0; i<n;i++)
						file << defaultfloat << w[i] << " ";
					file << "]" << endl;
					file << "r = [ ";
					for(unsigned int i = 0; i<n;i++)
						file << r[i] << " ";
					file << "]" << endl;
					file << "Rate of return of the portfolio: "  << setprecision(4) << (finalvalue/S-1) << endl;
					file << "V: " << fixed << setprecision(2) << finalvalue << endl;
					file.close();
					
					return true;
				}


