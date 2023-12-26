#include <iostream>
#include <vector>
using namespace std;

void printDouble(double d) {
    if (abs(d) < 1e-7) cout << 0.0;
    else cout << d;
}

struct Point {
    double x, y, z;
};

struct Particle {
    Point p,v;
    double m;
};

Point sum(Point p1, Point p2) {
    p1.x += p2.x;
    p1.y += p2.y;
    p1.z += p2.z;
    return p1;
}

Point mul(double a, Point p) {
    p.x *= a;
    p.y *= a;
    p.z *= a;
    return p;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);    
    cout.setf(ios::fixed);
    cout.precision(5);
    int n, k;
    while (cin >> n >> k) {
        vector < Particle > set (n, Particle());
        Particle centro_masas;
        centro_masas.p.x = 0;
        centro_masas.p.y = 0;
        centro_masas.p.z = 0;
        centro_masas.v.x = 0;
        centro_masas.v.y = 0;
        centro_masas.v.z = 0;
        centro_masas.m = 0;
        for (int i = 0; i < n; ++i) {
            cin >> set[i].p.x >> set[i].p.y >> set[i].p.z >> set[i].v.x >> set[i].v.y >> set[i].v.z >> set[i].m;
            centro_masas.p = sum(centro_masas.p, mul(set[i].m, set[i].p));
            centro_masas.v = sum(centro_masas.v, mul(set[i].m, set[i].v));
            centro_masas.m += set[i].m;
        }
        centro_masas.m = 1/centro_masas.m;
        centro_masas.p = mul(centro_masas.m, centro_masas.p);
        centro_masas.v = mul(centro_masas.m, centro_masas.v);
        double t_total = 0;
        while (k > 0) {
            double t;
            cin >> t;
            t_total += t;
            centro_masas.p = sum(centro_masas.p, mul(t, centro_masas.v));
            printDouble(centro_masas.p.x);
            cout << ' ';
            printDouble(centro_masas.p.y);
            cout << ' ';
            printDouble(centro_masas.p.z);
            cout << '\n';
            --k;
        }
        for (int i = 0; i < n; ++i) {
            set[i].p = sum(set[i].p, mul(t_total, set[i].v ) );
            printDouble (set[i].p.x);
            cout << ' ';
            printDouble (set[i].p.y);
            cout << ' ';
            printDouble (set[i].p.z);
            cout << '\n';
        }
        cout << '\n';
    }
}