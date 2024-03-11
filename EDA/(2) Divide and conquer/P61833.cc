#include <iostream>
#include <vector>
using namespace std;

typedef vector<vector<int>> Matriu;

Matriu mult(const Matriu& A, const Matriu& B, int n, int m) {
    Matriu C(2, vector<int>(2, 0));
    C[0][0] = (A[0][0]*B[0][0] + A[0][1]*B[1][0])%m;
    C[0][1] = (A[0][0]*B[0][1] + A[0][1]*B[1][1])%m;
    C[1][0] = (A[1][0]*B[0][0] + A[1][1]*B[1][0])%m;
    C[1][1] = (A[0][0]*B[0][1] + A[1][1]*B[1][1])%m;
    return C;
}

Matriu power(const Matriu& M, int n, int m) {
    if (n == 0) {
        Matriu X(2, vector<int>(2, 0));
        X[0][0] = X[1][1] = 1;
        return X;
    }
    else {
        Matriu aux = power(M, n/2, m);
        //HI: X = (M^(n/2)) mod m
        Matriu X = mult(aux, aux, n, m);
        //A: aux = ((X^(n/2)) mod m * (X^(n/2)) mod m)
        if (n%2 != 0) X = mult(X, M, n, m);
        return X;
    }
}

int main() {
    Matriu M(2, vector<int>(2));
    while (cin >> M[0][0] >> M[0][1] >> M[1][0] >> M[1][1]) {
        int n,m;
        cin >> n >> m;

        Matriu X = power(M, n, m);
        cout << X[0][0] << ' ' << X[0][1] << endl;
        cout << X[1][0] << ' ' << X[1][1] << endl;
        cout << "----------" << endl;
    }
}