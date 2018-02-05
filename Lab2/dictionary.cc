#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "word.h"
#include "dictionary.h"

using std::string;
using std::vector;

using namespace std;

Dictionary::Dictionary() {
	
}


bool Dictionary::contains(const string& word) const {
	ifstream fin;
	fin.open("words.txt");
	string line;
	if(fin.is_open()){
		while(getline(fin, line)){
			istringstream iss(line);
    		iss >> line;
			if(word == line){
				fin.close();
				return true;
			}
		}
	}
	fin.close();
	return false;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}
