#include <iostream>
using namespace std;

void drawRhombus(int n) {
    if (n == 1) cout << '*' << endl;

    else {
        drawRhombus(n - 1);

        // Print leading spaces
        

        // Print asterisks
        

        // Move to the next line
        

        // Print trailing spaces for the lower part of the rhombus
        

        // Print asterisks for the lower part of the rhombus
        

        // Move to the next line
        

        // Call the function recursively for the lower part of the rhombus
        drawRhombus(n - 1);
    }
}

int main() {
    int n;
    while (cin >> n) {
        // Call the recursive function to draw the rhombus
        drawRhombus(n);

        // Print a blank line between cases
        cout << endl;
    }
}