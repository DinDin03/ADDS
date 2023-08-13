#include <vector>

class EfficientTruckloads {
public:
    int numTrucks(int numCrates, int loadSize) {
        memo.assign(numCrates + 1, std::vector<int>(loadSize + 1, -1));
        return memoizedNumTrucks(numCrates, loadSize);
    }

private:
    std::vector<std::vector<int>> memo;

    int memoizedNumTrucks(int numCrates, int loadSize) {
        if (memo[numCrates][loadSize] != -1) {
            return memo[numCrates][loadSize];
        }

        if (numCrates <= loadSize) {
            return memo[numCrates][loadSize] = 1;
        }

        int half1 = numCrates / 2;
        int half2 = numCrates - half1;

        int trucksHalf1 = memoizedNumTrucks(half1, loadSize);
        int trucksHalf2 = memoizedNumTrucks(half2, loadSize);

        return memo[numCrates][loadSize] = trucksHalf1 + trucksHalf2;
    }
};
