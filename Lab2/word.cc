#include <string>
#include <vector>
#include "word.h"
#include <iostream>

using std::vector;
using std::string;

Word::Word(const string& w, const vector<string>& t) {
	word = w;
	trigrams = t;
}

string Word::get_word() const {
	return word;
}

vector<string> Word::get_trigrams() const{
	return trigrams;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	unsigned int matches = 0;
	for(auto &str : t){
		for (int i = matches; i < trigrams.size(); ++i){
			if(str == trigrams.at(i)){
				matches++;
			}
		}
	}
	return matches;
}
