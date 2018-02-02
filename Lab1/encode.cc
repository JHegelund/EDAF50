#include <string>
#include <iostream>
#include <fstream>
#include "coding.h"
using std::cout;
using std::endl;

/**unsigned char encode(unsigned char c){
  return c + 1;
}**/

int main(int argc, char** argv)
{
    if(argc == 0) return 1;
    std::string filename = argv[1];
    std::ifstream fin(filename.c_str());
    std::ofstream fout((filename + ".enc").c_str());
    char c;
    while (fin.get(c)){
      fout << encode(c);
    }
    fin.close();
    fout.close();
}
