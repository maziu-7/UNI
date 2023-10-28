#include <iostream>
using namespace std;
int main(){
    int n;
    bool parimpar = false;
    while (not parimpar and cin >> n){
        int y = n;
        int sum = 0;
        while (y > 0){
            if ((y%10)%2 != 0) sum += y%10;
            y/=10;
        }
        if (sum%2 == 0) parimpar = true;
    }
    if (parimpar) cout << n << endl;
    else cout << "no impar-par"<< endl;


}