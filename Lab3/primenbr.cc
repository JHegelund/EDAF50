#include <iostream>
#include <cstring>
#include <sstream>
#include "primenbr.h"

primenbr::primenbr(){
}

std::string primenbr::sievePrime(const unsigned long nbr){
	std::string primeString(nbr+1, 'P');

	primeString[0] = 'C';
	primeString[1] = 'C';

	long x = 2;
	long y;
	while(x*x <= nbr){
		if(primeString[x] == 'P'){
			y = x;
			while(y*x <= nbr){
				primeString[x*y] = 'C';
				y++;			
			}
		}
		x++;
	}
	return primeString;
}

std::string primenbr::toString(int x){
	std::stringstream s;
	s << x;
	return s.str();
}

std::string primenbr::primes(const std::string& sievePrimeString){
	std::string primes;
	for(int i = 0; i < sievePrimeString.size(); i++){
		if(sievePrimeString.at(i) == 'P'){
			primes += toString(i) + " ";
		}
	}
	return primes;
}