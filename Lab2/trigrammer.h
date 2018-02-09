#ifndef TRIGRAMMER_H
#define TRIGRAMMER_H

#include <string>
#include <vector>

class trigrammer {
public:
	trigrammer();
	std::vector<std::string> trigram(const std::string &s);
	std::vector<std::string> sort(std::vector<std::string> s);
	int main();
private:

};

#endif