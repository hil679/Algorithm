#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int dp[10001] = {};
    int wine[10001] = {};
    for (int i = 1; i <= n; i++) {
        cin >> wine[i];
    }
    dp[0] = 0;
    dp[1] = wine[1];
    dp[2] = wine[2] + dp[1];
//    dp[3] = (dp[1], wine[2] + dp[0]) + wine[3]
//    dp[4] = (dp[2], wine[3] + dp[1]) + wine[4]
//    dp[5] = (dp[3] , wine[4] + dp[2]) + wine[5]
    for (int i = 3; i <= n; i++) {
        dp[i] = max(dp[i-2], wine[i-1] + dp[i-3]) + wine[i];
        dp[i] = max(dp[i], dp[i-1]);
    }
    cout << dp[n];
    /*
    10 10
    41 51
    19 60 29,60
    25 76 54
    45 105 121, 121 -> 45 25  41 10
    15 120 91 -> 45 25 41 10
    13 104 134
    39 173 159
    43 202 177

    */
}