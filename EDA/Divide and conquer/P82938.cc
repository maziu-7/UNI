#include <iostream>
#include <vector>
using namespace std;

bool busca_der(int x, const vector<int>& v, int i, int j) {
	if (i > j) return false;
	int m = (i+j)/2;
	if (v[m] == x) return true;
	else if (v[m] < x) return busca_der(x, v, i, m-1);
	return busca_der(x, v, m+1, j);
}

bool busca_izq(int x, const vector<int>& v, int i, int j) {
	if (i > j) return false;
	int m = (i+j)/2;
	if (v[m] == x) return true;
	else if (v[m] > x) return busca_izq(x, v, i, m-1);
	return busca_izq(x, v, m+1, j);
}

int busca_pico(const vector<int>& v, int i, int j) {
	if (i >= j) { //1 o 2 elementos
		if (v[i] > v[j]) return i;
		return j;
	}
	int m = (i+j)/2;
	if (v[m-1] > v[m])  //el pico esta en la izq
		return busca_pico(v, i, m-1);
	else if (v[m] < v[m+1]) //el pico esta en la der
		return busca_pico(v, m+1, j);
	else return m;
}

bool search(int x, const vector<int>& v) {
	int pico = busca_pico(v, 0, v.size()-1);
	return busca_izq(x, v, 0, pico) or busca_der(x, v, pico, v.size()-1);
}


int main() {
    int n;
    while (cin >> n) {
        vector<int> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int m;
        cin >> m;
        while (m--) {
          int x;
          cin >> x;
          cout << ' ' << search(x, V);
        }
        cout << endl;
    }
}