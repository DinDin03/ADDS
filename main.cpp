#include <iostream>
#include "EfficientTruckloads.h"
#include "Truckloads.h"
#include "Reverser.h"

int main() {
    // Test Truckloads class
    Truckloads truckloads;
    int numCrates = 14;
    int loadSize = 3;
    int trucksNeeded = truckloads.numTrucks(numCrates, loadSize);
    std::cout << "Trucks needed using Truckloads class: " << trucksNeeded << std::endl;

    // Test EfficientTruckloads class
    EfficientTruckloads efficientTruckloads;
    int efficientTrucksNeeded = efficientTruckloads.numTrucks(numCrates, loadSize);
    std::cout << "Trucks needed using EfficientTruckloads class: " << efficientTrucksNeeded << std::endl;

    // Test Reverser class
    Reverser reverser;
    int reversedNumber = reverser.reverseDigit(12345);
    std::cout << "Reversed number: " << reversedNumber << std::endl;

    std::string originalString = "hello";
    std::string reversedString = reverser.reverseString(originalString);
    std::cout << "Reversed string: " << reversedString << std::endl;

    return 0;
}
