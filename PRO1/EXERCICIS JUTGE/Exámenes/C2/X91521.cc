#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n != 0){ // 22265
        int y = n;
        int sum = 0;
        int i = 1;
        while (y > 0){ //22265 // 2226
            if ((y%10)%2 != 0) sum += (y%10) *i; // 5%2!=0 --> sum = 5+1*1 = 5 
            else if ((y%10)%2 == 0) sum += (y%10+1)*i; // 6%2 == 0 --> sum = 6
            i*=10; //i = 10
            y/=10; // y = 2226
        }
        cout << sum << endl;
        cin >> n;
    }
}