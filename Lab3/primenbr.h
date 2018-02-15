#ifndef PRIMENBR_H
#define PRIMENBR_H

#include <iostream>

class primenbr {
public:
	primenbr();
	std::string toString(int);
	std::string sievePrime(const unsigned long nbr);
	std::string primes(const std::string& sievePrimeString);
private:

};

#endif