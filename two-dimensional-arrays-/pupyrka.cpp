#include <iostream>
#include <vector>

// Function to initialize the navel
void initNavel(std::vector<std::vector<bool>>& navel) {
    for (int i = 0; i < 12; i++) {
        navel.push_back(std::vector<bool>(12, true));
    }
}

// Function to display the state of the navel
void displayNavel(const std::vector<std::vector<bool>>& navel) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            std::cout << (navel[i][j] ? "o" : "x") << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// Function to burst the bubbles in the given region
void burstBubbles(std::vector<std::vector<bool>>& navel, int row1, int col1, int row2, int col2) {
    // Check arguments for validity
    if (row1 < 0 || row1 >= 12 || col1 < 0 || col1 >= 12 ||
        row2 < 0 || row2 >= 12 || col2 < 0 || col2 >= 12) {
        std::cerr << "Invalid coordinates!" << std::endl;
        return;
    }

    // Swap coordinates if necessary to ensure row1 <= row2 and col1 <= col2
    if (row1 > row2) std::swap(row1, row2);
    if (col1 > col2) std::swap(col1, col2);

    // Burst the bubbles in the region
    for (int i = row1; i <= row2; i++) {
        for (int j = col1; j <= col2; j++) {
            if (navel[i][j]) {
                navel[i][j] = false;
                std::cout << "Pop!" << std::endl;
            }
        }
    }
}

int main() {
    std::vector<std::vector<bool>> navel;
    initNavel(navel);

    while (true) {
        displayNavel(navel);

        int row1, col1, row2, col2;
        std::cout << "Enter the beginning and end coordinates of the region to burst (row1 col1 row2 col2): ";
        std::cin >> row1 >> col1 >> row2 >> col2;

        burstBubbles(navel, row1, col1, row2, col2);

        // Check if all bubbles have burst
        bool allPopped = true;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 12; j++) {
                if (navel[i][j]) {
                    allPopped = false;
                    break;
                }
            }
            if (!allPopped) break;
        }

        if (allPopped) {
            std::cout << "All bubbles have burst!" << std::endl;
            break;
        }
    }

    return 0;
}
