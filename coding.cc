#include "coding.h"

Coding::Coding() {}

Coding::~Coding() {}

unsigned char encode(unsigned char c){
  return c + 1;
}

unsigned char decode(unsigned char c){
  return c - 1;
}
