#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <fstream>
#include <sstream>
#include <map>

using namespace std;

Dictionary::Dictionary() {
	std::ifstream fin;
	words = std::map<int, vector<Word>>();
	fin.open("words.txt");
	while(fin.is_open()){
		string line;
		while(std::getline(fin, line)){
			Word w(Dictionary::wordify(line));
			int size = w.get_word().size();
			if(words.find(size)==words.end()){
				vector<Word> v;
				v.push_back(w);
				words.insert(std::pair<int, vector<Word>>(size, v));
			}else{
				words[size].push_back(w);
			}
		}
		std::cout << words[5].at(39).get_word() << endl;
		fin.close();
	}
}

Word Dictionary::wordify(const string& str){
	std::istringstream iss(str);
	string word;
	iss >> word;
	int tris;
	iss >> tris;
	vector<string> trigrams(tris);
	for(int i = 0; i < tris; i++){
		iss >> trigrams[i];
	}
	Word w(word, trigrams);
	return w;
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

vector<string> Dictionary::get_suggestions(const string& word)  const{
	vector<string> suggestions;	
	return suggestions;
}
