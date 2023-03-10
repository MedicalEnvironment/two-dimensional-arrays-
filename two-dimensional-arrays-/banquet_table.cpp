#include <iostream>
#include <vector>

using namespace std;

const int ROWS = 2;
const int COLS = 12;

int main() {
    // Initializing vectors
    vector<vector<int>> cutlery(ROWS, vector<int>(COLS, 0));
    vector<vector<int>> plates(ROWS, vector<int>(COLS, 0));
    vector<int> chairs(COLS, 1);

    // Adding a chair to the 5th seat of the 1st row
    chairs[4]++;

    // Removing a spoon from the 3rd seat of the 2nd row
    cutlery[1][2]--;

    // Sharing a spoon with a VIP
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (cutlery[i][j] == 0) {
                cutlery[i][j]++;
                cutlery[i][j+1]--;
                break;
            }
        }
    }

    // Removing a dessert plate from a VIP
    plates[0][0]--;

    return 0;
}
