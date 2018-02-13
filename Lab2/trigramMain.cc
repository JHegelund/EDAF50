#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "trigrammer.h"

using namespace std;

int main()
{
    trigrammer trig;
    string line;
    ifstream fin("words");
    if(fin.is_open()){
        ofstream fout("words.txt");
        vector<string> trigrams;
        while(getline(fin, line)){
            trigrams = trig.sort(trig.trigram(line));
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