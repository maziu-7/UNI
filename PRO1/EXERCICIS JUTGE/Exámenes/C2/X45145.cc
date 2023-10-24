#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    while (n != -1) {
        int y = n;
        int i = 1;
        int sum = 0;
        while (y > 0){
            if ((y%10)%2 != 0){
                 sum += y%10 * i;
                 i *= 10;
            }
            y/=10;
        }
        cout << sum << endl;
        cin >> n;
    }
}