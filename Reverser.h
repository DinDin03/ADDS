#ifndef REVERSER_H
#define REVERSER_H

#include <string>
#include "Reverser.h"

class Reverser {
public:
    int reverseDigit(int value);
    std::string reverseString(const std::string& characters);

private:
    int getNumDigits(int value);
};

#endif // REVERSER_H
