#include <iostream>
#include <cstring>

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

int main(){
	std::string primeNbr = sievePrime(200);

	std::cout << "Prime numbers between 1 and 200:" << std::endl;
	for(int i = 1; i <= 200; i++){
		if(primeNbr[i] == 'P'){
			std::cout << i << " ";
		}
	}

	std::cout << std::endl;

	std::string largestPrime = sievePrime(100000);

	std::cout << "Largest prime less than 100 000: " << largestPrime.rfind("P") << std::endl;;
}