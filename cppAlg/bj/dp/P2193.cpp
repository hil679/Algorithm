#include <iostream>
using namespace std;
/*
1
10
100 101
1000 1001 1010
1000
*/
int main() {
    int n;
    cin >> n;
    long dp[91][2] = {0};
    dp[1][1] = 1;
    dp[2][0] = 1;
    dp[2][1] = 0;

    for (int i = 3; i <= n; i++) {
        dp[i][1] = dp[i-1][0];
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
    }

    cout << dp[n][0] + dp[n][1];

}