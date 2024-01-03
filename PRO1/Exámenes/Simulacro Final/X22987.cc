#include <iostream>
#include <vector>
using namespace std;

int countConstantSubmatrices(const vector<vector<int>>& matrix, int n, int m) {
    int count = 0;

    for (int size = 1; size <= min(n, m); ++size) {
        for (int i = 0; i <= n - size; ++i) {
            for (int j = 0; j <= m - size; ++j) {
                // Check if the submatrix is constant
                int symbol = matrix[i][j];
                bool isConstant = true;
                for (int row = i; row < i + size; ++row) {
                    for (int col = j; col < j + size; ++col) {
                        if (matrix[row][col] != symbol) {
                            isConstant = false;
                            break;
                        }
                    }
                }
                // Increment count if the submatrix is constant
                if (isConstant) {
                    ++count;
                }
            }
        }
    }
    return count;
}

int main() {
    int n, m;

    while (cin >> n >> m) {
        vector<vector<int>> matrix(n, vector<int>(m));
        // Input matrix
        for (int i = 0; i < n; ++i) {
            string row;
            cin >> row;
            for (int j = 0; j < m; ++j) matrix[i][j] = row[j] - '0';
        }
        cout << countConstantSubmatrices(matrix, n, m) << endl;
    }
}