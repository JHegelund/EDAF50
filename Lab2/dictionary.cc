#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cassert>
#include "word.h"
#include "dictionary.h"
#include <fstream>
#include <sstream>
#include <map>
#include "trigrammer.h"

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
	fin.open("words.txt");
	while(fin.is_open()){
		string line;
		while(std::getline(fin, line)){
			std::istringstream iss(line);
			iss >> line;
			if(word == line){
				fin.close();
				return true;
			}
		}
		fin.close();
	}
	return false;
}

vector<string> Dictionary::get_suggestions(const string& word) const{
	vector<string> suggestions;	
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string>& suggestions, const string word) const{
	double size = word.size();
	if(size<2){
		return;
	}else{
		trigrammer trig;
		vector<string> tris(trig.sort(trig.trigram(word)));
		Word w(word, tris);
		for(int i = size-1; i <= size+1; i++){
			for(int j = 0; j < words.at(i).size(); j++){
				if(((size-2.0)/2.0) <= w.get_matches(words.at(i).at(j).get_trigrams())){
					suggestions.push_back(words.at(i).at(j).get_word());
				}
			}
		}
	}
}

void Dictionary::rank_suggestions(vector<string>& suggestions, const string word) const{
	vector<pair<int, string>> costVec;
	costVec.reserve(suggestions.size());
	int a[26][26];
	a[0][0]=0;
	int cost;
	for(auto& str : suggestions){
		for(int i = 1; i <= word.size(); i++){
			a[i][0] = i;
		}
		for(int i = 1; i <= str.size(); i++){
			a[0][i] = i;
		}
		int temp;
		for(int iw = 0, i = 1; iw < word.size(); iw++, i++){
			for(int jw = 0, j = 1; jw < str.size(); jw++, j++){
				int temp;
				if(word.at(iw) == str.at(jw)){
					temp = a[i-1][j-1];
				}else{
					temp = a[i-1][j-1] + 1; 
				}
				a[i][j] = min(temp, min((a[i-1][j]+1), (a[i][j-1]+1)));
			}
		}
		cost = a[word.size()][str.size()];
		costVec.push_back(make_pair(cost, str));
	}	
	sort(costVec.begin(), costVec.end());
	assert(costVec.size() == suggestions.size());
	int i = 0;
	for(auto &par : costVec){
		suggestions.at(i) = par.second;
		i++;
	}
}

void Dictionary::trim_suggestions(vector<string> &suggestions) const{
	if(suggestions.size() > 5){
		suggestions.resize(5);
	}
}