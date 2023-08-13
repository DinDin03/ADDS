#ifndef EFFICIENTTRUCKLOADS_H
#define EFFICIENTTRUCKLOADS_H

#include <vector>

class EfficientTruckloads {
public:
    int numTrucks(int numCrates, int loadSize);

private:
    std::vector<std::vector<int>> memo;
    int memoizedNumTrucks(int numCrates, int loadSize);
};

#endif // EFFICIENTTRUCKLOADS_H
