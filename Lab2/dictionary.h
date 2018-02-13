#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <map>
#include "word.h"

class Dictionary {
public:
	Dictionary();
	Word wordify(const std::string& str);
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word) const;
private:
	std::map<int, std::vector<Word>> words;
	void add_trigram_suggestions(std::vector<std::string>& suggestions, const std::string word) const;
	void rank_suggestions(std::vector<std::string>& suggestions, const std::string word) const;
	void trim_suggestions(std::vector<std::string>& suggestions) const;
};

#endif
