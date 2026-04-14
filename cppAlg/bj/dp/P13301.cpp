#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[81];
    arr[1] = 1;
    arr[2] = 1;
    for (int i = 3; i <= 80; i++) {
        arr[i] = arr[i-1] + arr[i-2];
    }
    if (n == 1) cout << 4;
    else if (n == 2) cout << 6;
    else if (n == 3) cout << 10;
    else {
        cout << arr[n] * 3 + arr[n-1] * 2 + arr[n-2] * 2 + arr[n-3];
    }
}