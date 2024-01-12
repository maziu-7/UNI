#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matrix;

int main(){
    int n, m;
    char x;
    while(cin >> n) {
        cin >> m;
        Matrix matrix(n, vector<int> (m));
        Matrix row(n, vector<int> (10));
        Matrix column(m, vector<int> (10));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> x;
                matrix[i][j] = x - '0';
                ++row[i][matrix[i][j]];
                ++column[j][matrix[i][j]];
            }
        }
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cout << (row[i][matrix[i][j]]%10 + column[j][matrix[i][j]]%10)%10;
            }
            cout << endl;
        }
        cout << endl;
    }
}