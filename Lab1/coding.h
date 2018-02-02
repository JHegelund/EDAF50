#ifndef CODING_H
#define CODING_H
#include <string>

class Coding {
public:
	Coding();

	~Coding();

	std::string do_encode(std::string s);

	std::string do_decode(std::string s);

	bool test_coding();
};

unsigned char encode(unsigned char s);

unsigned char decode(unsigned char s);

#endif
