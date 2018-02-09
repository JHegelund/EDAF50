#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "trigrammer.h"

using namespace std;

trigrammer::trigrammer(){

}

vector<string> trigrammer::trigram(const string &s){
    if(s.size() <= 3){
         vector<string> triagrams;
         return triagrams;
    }
    vector<string> triagrams(s.size() - 2);
    int i = 0;
    while(i < s.size() - 2){
        triagrams[i] = s.substr(i, 3);
        transform(triagrams[i].begin(), triagrams[i].end(), triagrams[i].begin(), ::tolower);
        i++;
    }
    return triagrams;
}

vector<string> trigrammer::sort(vector<string> s){
    vector<string> sorted(s.size());
    if(s.empty()) return sorted;
    for(int i = 0; i < s.size(); i++){
        int index = 0;
        for(int j = 0; j < s.size(); j++){
            if(s[i] > s[j]){
                index++;
            }
        }
        sorted[index] = s[i];
    }
    return sorted;
}


int trigrammer::main()
{
    string line;
    ifstream fin("words");
    if(fin.is_open()){
        ofstream fout("words.txt");
        vector<string> trigrams;
        while(getline(fin, line)){
            trigrams = sort(trigram(line));
            transform(line.begin(), line.end(), line.begin(), ::tolower);
            if(!trigrams.empty()){
                fout << line << ' ' << trigrams.size() << ' ';
                string trigramsString;
                for(auto& str : trigrams){
                    trigramsString += str;
                    trigramsString += ' ';
                }
                fout << trigramsString << '\n';
            } else {
                fout << line << ' ' << 0 << '\n';
            }
        }
        fout.close();
    }
    fin.close();
    return 0;
}