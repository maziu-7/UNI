#include <iostream>
using namespace std;

bool is_prime(int n) {
    if (n == 1) return false;
    if (n == 2) return true;
    for (int sqrt = 2; sqrt < n; ++sqrt) {
        if (n%sqrt == 0) return false;
    }
    return true;
}

bool is_perfect_prime(int n) {
    if ()
}