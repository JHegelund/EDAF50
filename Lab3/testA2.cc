#include "primenbr.h"
#include <iostream>
#include <fstream>
#include <assert.h>

using std::iostream;

int main(){
	std::ifstream fin("testA2string.txt");
	std::string CPC; 
	getline(fin, CPC);
	primenbr pbn;	
	assert(CPC == pbn.sievePrime(35));
	std::ifstream finn("primenbr_sequence35.txt");
	std::string primenbrs;
	getline(finn, primenbrs);
	assert(primenbrs == pbn.primes(pbn.sievePrime(35)));
	std::cout << "test passed successfully" << std::endl;
	return 0;
}