#include <fstream>
#include <iostream>
#include "tagremover.h"
#include <assert.h>

using namespace std;

int main(){
	TagRemover tr(cin);
	ofstream fout("testA1depo.txt");
	tr.print(fout);
	fout.close();
	ifstream correct("notags");
	ifstream trResult("testA1depo.txt");
	string temp1, temp2;
	while(getline(correct, temp1)){
		getline(trResult, temp2);
		assert(temp1 == temp2);
	}
	correct.close();
	trResult.close();
	cout << "test passed succesfully" << endl;
	return 0;
}