#include <iostream>

using namespace std;

// Function to generate a grid with n x m squares of side 'side'
void generateGrid(int n, int m, int side) {
    // Loop to print the rows
    for (int i = 0; i < n; i++) {
        // Loop to print each row
        for (int j = 0; j < m; j++) {
            // Loop to print each square within the row
            for (int k = 0; k < side; k++) {
                for (int l = 0; l < side; l++) {
                    cout << "*";
                }
                cout << " ";
            }
        }
        cout << endl;
    }
}

int main() {
    int n, m, side;

    // Read input and generate grids
    while (cin >> n >> m >> side) {
        generateGrid(n, m, side);
        cout << endl;
    }

    return 0;
}
