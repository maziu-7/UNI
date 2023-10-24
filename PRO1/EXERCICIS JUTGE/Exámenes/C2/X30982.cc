#include <iostream>
using namespace std;

int main(){
    int n, m;
    bool primerd = false;
    cin >> n;
    while (not primerd and cin >> m){
        int y = m;
        int countn = 0;
        while (y > 0){
            if (y%10 == n) ++countn;
            y/=10;
        }
        if (countn%2 == 0) primerd = true;
    }
    if (primerd) cout << m << endl;
    else cout << "no d-par" << endl;


}

