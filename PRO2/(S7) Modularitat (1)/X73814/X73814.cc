#include "Estudiant.hh"
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<Estudiant> v(n);
    for (int i = 0; i < n; ++i) {
        v[i].llegir();
    }

    for (int i = 0; i < salida.size(); ++i) {
        salida[i].escriure();
    }
}