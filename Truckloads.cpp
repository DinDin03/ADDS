class Truckloads {
public:
    int numTrucks(int numCrates, int loadSize) {
        if (numCrates <= loadSize) {
            return 1;  // Base case: One truck needed to load the pile
        }

        int half1 = numCrates / 2;
        int half2 = numCrates - half1;

        // Recursively calculate the number of trucks needed for each half
        int trucksHalf1 = numTrucks(half1, loadSize);
        int trucksHalf2 = numTrucks(half2, loadSize);

        return trucksHalf1 + trucksHalf2;
    }
};
