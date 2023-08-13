#include <cmath>
#include <string>
#include "Reverser.h"

int Reverser::getNumDigits(int value) {
  int count = 0;
  while (value > 0) {
    value /= 10;
    ++count;
  }
  return count;
}

int Reverser::reverseDigit(int value) {
  if (value < 10) {
    return value;
  }
  return (value % 10) * pow(10, getNumDigits(value) - 1) +
         reverseDigit(value / 10);
}

std::string Reverser::reverseString(const std::string& characters) {
  if (characters.empty()) {
    return "";
  }
  return reverseString(characters.substr(1)) + characters[0];
}


