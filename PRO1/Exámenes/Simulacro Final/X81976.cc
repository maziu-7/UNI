#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;

    while (cin >> n >> m) {
        vector<vector<int>> u(n, vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char digit;
                cin >> digit;
                u[i][j] = digit - '0';
            }
        }
        vector<vector<int>> v(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int d = u[i][j];
                for (int col = 0; col < m; ++col) if (u[i][col] == d) v[i][j] = (v[i][j] + 1) % 10;

                for (int row = 0; row < n; ++row) if (u[row][j] == d) v[i][j] = (v[i][j] + 1) % 10;
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) cout << v[i][j];
            cout << endl;
        }
        cout << endl;
    }
}