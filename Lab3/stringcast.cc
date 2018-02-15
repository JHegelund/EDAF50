#include <iostream>
#include <sstream>
#include <stdexcept>
#include "date.h"

template <typename T>
T string_cast(const std::string& s){
	std::istringstream ss(s);
	T object;
	if (ss >> object){
		return object;
	} else {
		throw std::invalid_argument("Invalid");
	}
}

int main(){
	try{
		int i = string_cast<int>("123");
		double d = string_cast<double>("12.34");
		Date date = string_cast<Date>("2015-01-10");
		std::cout << i << std::endl;
    	std::cout << d << std::endl;
    	std::cout << date << std::endl;
	} catch (std::invalid_argument& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}