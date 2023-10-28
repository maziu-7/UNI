#include <iostream>
using namespace std;

int main() {
    char x;
    int c_counter = 0;
    int d_counter = 0;
    bool no_b = false;
    bool a_before = false;
    bool a_after = false;
    bool primer = false;
    while (cin >> x) {
        if (primer) {
            if (x == 'a') a_before = true;
            primer = false;
        }
        if (x == 'c') {
            if (a_before and no_b) ++c_counter;
        }
        else if (x == 'd') {
            if (a_after)
        }
        cout << c_counter << ' ' << d_counter << endl;
    }
}