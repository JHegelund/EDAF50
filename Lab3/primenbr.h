#ifndef PRIMENBR_H
#define PRIMENBR_H

#include <iostream>

class primenbr {
public:
	int main();
	std::string toString(int);
	std::string sievePrime(const unsigned long nbr);
	std::string primes(const std::string& sievePrimeString);
private:
	std::istream &instream;
};

#endif