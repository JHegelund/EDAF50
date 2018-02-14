#include <iostream>
#include <cstring>
#include <sstream>

std::string sievePrime(const unsigned long nbr){
	std::string primeString(nbr, 'P');

	primeString[0] = 'C';
	primeString[1] = 'C';

	long x = 2;
	long y;
	while(x < nbr){
		if(primeString[x] == 'P'){
			y = x;
			while(y*x < nbr){
				primeString[x*y] = 'C';
				y++;			
			}
		}
		x++;
	}
	return primeString;
}

std::string toString(int x){
	std::stringstream s;
	s << x;
	return s.str();
}

std::string primes(const std::string& sievePrimeString){
	std::string primes;
	for(int i = 0; i < sievePrimeString.size(); i++){
		if(sievePrimeString.at(i) == 'P'){
			primes += toString(i) + " ";
		}
	}
	return primes;
}

int main(){
	std::string sievePrimes = sievePrime(200);

	std::cout << "Prime numbers between 1 and 200:" << std::endl;
	std::string primeNbr = primes(sievePrimes);
	std::cout << primeNbr << std::endl;

	std::cout << std::endl;

	std::string largestPrime = sievePrime(100000);

	std::cout << "Largest prime less than 100 000: " << largestPrime.rfind("P") << std::endl;;

	return 0;
}