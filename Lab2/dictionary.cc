#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <fstream>
#include <sstream>

using std::string;
using std::vector;

Dictionary::Dictionary() {
	std::ifstream fin;
	words = std::map<int, vector<Word>>;
	fin.open("Words.txt");
	while(fin.is_open()){
		string line;
		while(std::getline(fin, line)){
			std::istringstream iss(line);
			string word;
			iss >> word;
			int tris;
			iss >> tris;
			vector<string> trigrams[tris];
			for(int i = 0; i < tris; i++){
				iss >> trigrams[i];
			}
			Word w(word, trigrams);
			int size = w.get_word().size();
			if(!words.find(size)){
				vector<Word> v;
				v.push_back(w);
				words.add(size, v);
			}else{
				words.get(size).push_back(w);
			}
		}
		fin.close();
	}
	return false;
}

bool Dictionary::contains(const string& word) const {
	std::ifstream fin;
	fin.open("Words.txt");
	while(fin.is_open()){
		string line;
		while(std::getline(fin, line)){
			std::istringstream iss(line);
			iss >> line;
			if(word == line){
				std::cout << line << std::endl;
				fin.close();
				return true;
			}
		}
		fin.close();
	}
	return false;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;	
	return suggestions;
}
