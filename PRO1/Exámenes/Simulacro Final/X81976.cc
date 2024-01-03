#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> Row;
typedef vector<Row> Matrix;

void read(Matrix& data) {
    int row = data.size();
    int col = data[0].size();

    for (int i = 0; i < row; ++i) {
        for (int j = 0; i < col; ++j) {
            int num;
            cin >> num;
            data[i][j] = num;
        }
    }
}

void check_num(Matrix& data) {
    
}

int main() {
    int n,m;
    while (cin >> n >> m) {
        Matrix data(n, Row(m));
        read(data);

    }
}