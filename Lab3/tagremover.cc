#include <iostream>
#include <cstring>
#include <regex>
#include <fstream>
#include "tagremover.h"


using std::string;
using std::fstream;

TagRemover::TagRemover(std::istream &in) : instream(in) {
}

void TagRemover::print(std::ostream &out){
	std::string output;
	std::string line;

	while(std::getline(instream, line)){
		std::ifstream fin(line);

		if(fin.is_open()){
			string test;
			bool linebreak = false;
			while(getline(fin, test)){
				if(test.find("<") != std::string::npos){
					if(test.find(">") == std::string::npos){
						linebreak = true;
					}
				}
				if(test.find(">") != std::string::npos && linebreak == true){
					auto x = test.find(">");
					test.insert((x + 2), "\n");
					output += test + " \n";
					linebreak = false;
				} else {
					output += test + " \n";
				}
			}

			while(output.find("<") != std::string::npos){
				auto i1 = output.find("<");
				auto i2 = output.find(">");
				output.erase(i1, (i2 - i1) + 2);
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
				output.replace(i6, 5, "&");
			}
			out << output;
			fin.close();
		}
	}
}