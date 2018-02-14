#include <iostream>
#include <sstream>
#include "date.h"

template <typename T>
std::string string_cast(T t){
	std::stringstream s;
	s << t;
	return s.str();
}

int main(){
	try{
		int i = string_cast<int>("123");
		double d = string_cast<double>("12.34");
		Date date = string_cast<Date>("2015-01-10");
	} catch (std::invalid_argument& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
}