#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[1001];
    int dpInc[1001];
    int dpDec[1001];

    for (int i =1; i <= n; i++) {
        cin >> arr[i];
        dpInc[i] = 1;
        dpDec[i] = 1;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            if (arr[i] > arr[j]) {
                dpInc[i] = max(dpInc[i], dpInc[j] + 1);
            }
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = n; j >= i; j--) {
                if (arr[i] > arr[j]) {
                    dpDec[i] = max(dpDec[i], dpDec[j] + 1);
                }
            }
    }

    int m = 0;
    for (int i = 1; i <= n; i++) {
        m = max(m, dpInc[i] + dpDec[i]);
    }
    cout << m-1;
    return 0;
}
