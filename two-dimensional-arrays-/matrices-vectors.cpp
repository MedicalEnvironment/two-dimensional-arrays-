#include <iostream>
#include <vector>

int main() {
    // Read input from user
    std::vector<float> b(4);
    std::vector<std::vector<float>> a(4, std::vector<float>(4));

    std::cout << "Enter vector b (four components): ";
    for (int i = 0; i < 4; i++) {
        std::cin >> b[i];
    }

    std::cout << "Enter matrix a (4x4): ";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> a[i][j];
        }
    }

    // Multiply vector b by matrix a
    std::vector<float> c(4, 0.0);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            c[i] += b[j] * a[i][j];
        }
    }

    // Output result
    std::cout << "Resulting vector c: ";
    for (int i = 0; i < 4; i++) {
        std::cout << c[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
