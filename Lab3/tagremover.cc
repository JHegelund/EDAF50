#include <iostream>
#include <cstring>
#include <regex>
#include "tagremover.h"

TagRemover::TagRemover(std::istream &in) : instream(in) {
}

void TagRemover::print(std::ostream &out){
	std::string output;
	std::string line;

	while(std::getline(instream, line)){
		output += line + "\n";

		while(output.find("<") != std::string::npos){
			auto i1 = output.find("<");
			auto i2 = output.find(">");
			output.erase(i1, (i2 - i1) + 1);
		}

		while(output.find("&lt;") != std::string::npos){
			auto i3 = output.find("&lt;");
			output.replace(i3, 4, "<");
		}

		while(output.find("&gt;") != std::string::npos){
			auto i4 = output.find("&gt;");
			output.replace(i4, 4, ">");
		}

		while(output.find("&nbsp;") != std::string::npos){
			auto i5 = output.find("&nbsp;");
			output.replace(i5, 6, " ");
		}

		while(output.find("&amp;") != std::string::npos){
			auto i6 = output.find("&amp;");
			output.replace(i6, 5, "");
		}
		out << output;
	}

	/**
	while(std::getline(instream, line)){
		auto i1 = line.find("<");
		if(i1 != std::string::npos){
			auto i2 = line.find(">");
			if(i2 != std::string::npos){
				int a = (i2 - i1) + 1;
				std::cout << a << std::endl;
				line.erase(i1, a);
			} else {
				line.replace(i1, line.size(), " ");
			}
		}
		output += line + "\n";
		out << output;
	}**/
	

	/**output = regex_replace(output, std::regex("<[^<>]*>"), "");
  	output = regex_replace(output, std::regex("&lt;"), "<");
  	output = regex_replace(output, std::regex("&gt;"), ">");
  	output = regex_replace(output, std::regex("&nbsp;"), " ");
  	output = regex_replace(output, std::regex("&amp;"), "&");**/

  	//out << output;
}