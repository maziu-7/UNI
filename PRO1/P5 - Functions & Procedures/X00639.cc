#include <iostream>
using namespace std;

bool c_frac(int n1, int d1, int n2, int d2) {
    return (n1/double(d1) < n2/double(d2));
}