#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        int x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
        int norm = (r1 + r2) * (r1 + r2);
        int innerNorm = (r1 - r2) * (r1 - r2);

        if (x1 == x2 && y1 == y2 && r1 == r2) cout << -1 << "\n";
        else if (x1 == x2 && y1 == y2 && r1 != r2) cout << 0 << "\n";
        else if (norm == dist || dist == innerNorm) cout << 1 << "\n";
        else if (norm < dist || innerNorm > dist) cout << 0 << "\n";
        else cout << 2 << "\n";
        t--;
    }
}