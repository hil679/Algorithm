#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[10000];
    int max = 0;
    for (int i = 0; i < n; i++) {
        cin >>arr[i];
        if (max < arr[i]) max = arr[i];
    }
    int m;
    cin >> m;

    int left = 1, right = max+1;
    while (left < right) {
        int mid = left + (right - left)/2;
        int money = 0;
        for (int i = 0; i < n; i++) {
            if (mid - arr[i] >= 0) money += arr[i];
            else money += mid;
        }

        if (money > m) right = mid;
        else left = mid + 1;
//        cout << money << " "<< mid << endl;
    }
    cout << left - 1;
}