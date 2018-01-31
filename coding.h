#ifndef CODING_H
#define CODING_H
#include <string>

class Coding {
public:
	Coding();

	~Coding();

	std::string do_encode(std::string s);

	std::string do_decode(std::string s);

	static unsigned char encode(unsigned char s);

	static unsigned char decode(unsigned char s);

	bool test_coding();
};

#endif
