#include <iostream>
#include <vector>

int main() {
    const int WIDTH = 5;
    const int HEIGHT = 5;
    const int DEPTH = 10;

    // initialize the world with user-input block heights
    std::vector<std::vector<std::vector<int>>> world(WIDTH, std::vector<std::vector<int>>(HEIGHT, std::vector<int>(DEPTH)));
    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            int height;
            std::cout << "Enter the height of the block at (" << x << ", " << y << "): ";
            std::cin >> height;
            for (int z = 0; z < height; z++) {
                world[x][y][z] = 1;
            }
        }
    }

    // get user input for the slice level to display
    int slice_level;
    std::cout << "Enter the slice level to display (0-9): ";
    std::cin >> slice_level;

    // output the horizontal slice of the world
    std::cout << "Horizontal slice at level " << slice_level << ":\n";
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            std::cout << (world[x][y][slice_level] ? "1" : "0") << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
