#include <iostream>
#include <sstream>
#include "date.h"

template <typename T>
std::string toString(T t){
	std::stringstream s;
	s << t;
	return s.str();
}

int main(){
	double d = 1.234;
	Date today;
	std::string sd = toString(d);
	std::string st = toString(today);
	std::cout << std::endl << sd << std::endl;
}