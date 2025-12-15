#include <iostream>
using namespace std;

string video[64];

void compress(int x, int y, int size) {
    char cur = video[y][x];
    for (int i = y; i < y+size; i++) {
        for(int j = x; j < x+size; j++) {
            if (cur != video[i][j]) {
                cout << "(";
                compress(x, y, size / 2);
                compress(x+size/2, y, size / 2);
                compress(x, y+size/2, size / 2);
                compress(x+size/2, y+size/2, size / 2);
                cout << ")";
                return;
            }
        }
    }
    cout << cur;
}

int main() {
    int n;
    cin >> n;


    for (int i = 0; i < n; i++) {
        cin >> video[i];
    }

    compress(0, 0, n);
}