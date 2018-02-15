#include <iostream>
#include <cstring>
#include <sstream>
#include "primenbr.h"

int main(){
	primenbr pbn;
	std::string sievePrimes = pbn.sievePrime(200);

	std::cout << "Prime numbers between 1 and 200:" << std::endl;
	std::string primeNbr = pbn.primes(sievePrimes);
	std::cout << primeNbr << std::endl;

	std::cout << std::endl;

	std::string largestPrime = pbn.sievePrime(100000);

	std::cout << "Largest prime less than 100 000: " << largestPrime.rfind("P") << std::endl;;

	return 0;
}