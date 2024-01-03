#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

// Pre: Let n be v.size(). Then, for each i in {0..n-2}, |v[i]-v[i+1]|<=2 holds.
//      In addition, there is exactly one i in {0..n-2} satisfying |v[i]-v[i+1]|=1.
// Post: The function returns this particular i in {0..n-2} satisfying |v[i]-v[i+1]|=1.
int positionDistance1(const vector<int> &v) {
    int num;
    bool found = false;
    while (not found) {
        for (int i = 0; i < v.size(); ++i) {
            if (v[i]-v[i+1] > 0) {
                if (v[i]-v[i+1] == 1) {
                    num = i;
                    found = true;
                }
            }
            else if (v[i]-v[i+1] < 0) {
                if (v[i]-v[i+1] == -1) {
                    found = true;
                    num = i;
                }
            }
        }
    }
    return num;
}

int main()  {
    vector<vector<int> > listinputs;
    vector<int> listsolutions;
    vector<int> listattempts;
    int n;
    while (cin >> n) {
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        listinputs.push_back(v);
        listsolutions.push_back(0);
    }
    int repetitions = max(1, 100000/int(listinputs.size()));
    for (int index = 0; index < int(listinputs.size()); index++)
        for (int i = 0; i < repetitions; i++)
            listattempts.push_back(index);
    random_shuffle(listattempts.begin(), listattempts.end());
    for (int r = 0; r < int(listattempts.size()); r++) {
        int i = listattempts[r];
        listsolutions[i] = positionDistance1(listinputs[i]);
    }
    for (int i = 0; i < int(listsolutions.size()); i++)
        cout << listsolutions[i] << endl;
}