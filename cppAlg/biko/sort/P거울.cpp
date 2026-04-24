#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, s;
    cin >> n >> s;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr,arr+n);
    int ans = s;

    //2b1 - a
    //2b2 - 2b1 + a
    int negCnt = n / 2;
    long negNum = 0, posNum = 0;
    for (int i = 0; i < negCnt; i++) {
        negNum += arr[i];
    }
    for (int i = negCnt; i < n; i++) {
        posNum += arr[i];
    }

    if (n % 2 == 1)
        cout << 2*posNum - 2 * negNum - s;
    else
        cout << 2*posNum - 2 * negNum + s;
  return 0;
}