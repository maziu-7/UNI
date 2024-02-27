#include <iostream>
#include <vector>
using namespace std;

int position(double x, const vector<double>& v, int left, int right) {
	int middle = (right - left)/2 + left;
	if (left > right) return -1;
	if (left == right) return (v[left] == x) ? left : -1;
	
	if (v[middle] == x) return position(x, v, left, middle);
	else if (v[middle] > x) return position(x, v, left, middle);
	else return position(x, v, middle+1, right);
}

int first_occurrence(double x, const vector<double>& v) {
	return position(x, v, 0, int(v.size()-1));
}

int main() {
    int n;
    while (cin >> n) {
        vector<double> V(n);
        for (int i = 0; i < n; ++i) cin >> V[i];
        int t;
        cin >> t;
        while (t--) {
            double x;
            cin >> x;
            cout << first_occurrence(x, V) << endl;
        }
    }
}