#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[100000];
    int dp[100000][4] = {};
    //0:뺀것없이 최대 or 나만, 1: 지금까지 최대 + 나, 2: 나버리고 이전까지 뺸 것없이 최대 ,3: 최종 최대

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    dp[0][0] = arr[0];
    dp[0][1] = arr[0];
    dp[0][2] = arr[0];
    dp[0][3] = max(-100000000, arr[0]);
    int m = dp[0][3];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i-1][0] + arr[i], arr[i]);
        dp[i][1] = dp[i-1][3]+arr[i];
        dp[i][2] = dp[i-1][0];
        dp[i][3] = max(max(dp[i][0], dp[i][1]), dp[i][2]);
        if (m < dp[i][3]) m = dp[i][3];
    }

    //4 -1 -2 5
    //4  3  1 6 -> 6
    cout << m;

    return 0;
}