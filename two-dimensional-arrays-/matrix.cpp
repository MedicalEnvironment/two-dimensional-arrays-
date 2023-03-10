#include <iostream>
#include <vector>

int main() {
    // Initialize the two matrices
    std::vector<std::vector<int>> A(4, std::vector<int>(4, 0));
    std::vector<std::vector<int>> B(4, std::vector<int>(4, 0));

    // Input the two matrices
    std::cout << "Enter matrix A:\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cin >> A[i][j];
        }
    }

    std::cout << "Enter matrix B:\n";
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            std::cin >> B[i][j];
        }
    }

    // Compare the two matrices for equality
    bool areEqual = true;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (A[i][j] != B[i][j]) {
                areEqual = false;
                break;
            }
        }
        if (!areEqual) break;
    }

    if (areEqual) {
        // Convert one of the matrices to diagonal form
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (i != j) A[i][j] = 0;
            }
        }

        // Output the diagonal matrix
        std::cout << "The matrices are equal.\n";
        std::cout << "Matrix A in diagonal form:\n";
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                std::cout << A[i][j] << " ";
            }
            std::cout << "\n";
        }
    } else {
        std::cout << "The matrices are not equal.\n";
    }

    return 0;
}
