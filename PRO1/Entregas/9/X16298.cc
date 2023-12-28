#include <iostream>
#include <vector>
using namespace std;

// Pre: s is formed with three different characters c1,c2,c3, and is of the form c1...c1c2...c2c3...c3.
// Post: n1, n2, n3 are the number of occurrences of c1, c2, c3 in s, respectively.
void numberOccurrences(const string &s, int &n1, int &n2, int &n3) {
    int t = s.size();
    for (int i = 0; i < t; ++i) {
        if (t[i] == ':') {
            ++n1;
            if (t[i+1] == '-') {
                ++n2;
            }
            else ++n1;
        }
    }
}

// Pre: s begins with one or more occurrences of a character c1, followed by one or more
//      occurrences of a character c2, followed by one or more occurrences of a character c3,
//      and there are no more characters in s.
//      moreover, either c1c2c3 = ":-)" or c1c2c3 = "(-:" or c1c2c3 = ":-(" or c1c2c3 = ")-:".
// Post: If c1c2c3 = ":-)" or c1c2c3 = "(-:", the function returns the number of happy subsequences.
//       If c1c2c3 = ":-(" or c1c2c3 = ")-:", the function returns the number of sad subsequences.
int numberHappyOrSadSubsequences(const string &s) {
    int n1 = 0, n2 = 0, n3 = 0, aux = 1;
    numberOccurrences(s, n1, n2, n3);
    aux *= n1;
    aux *= n2;
    aux *= n3;
    return aux;
}

int main() {
    int n1 = 0, n2 = 0, n3 = 0;
    string s;
    cin >> s;
    numberOccurrences(s, n1, n2, n3);
    cout << numberHappyOrSadSubsequences(s) << endl;
}