#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t > 0) {
        int n;
        cin >> n;
        int dp[2][100001];
        for (int i = 0; i < 2; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> dp[i][j];
            }
        }

        dp[0][0] = dp[0][0];
        dp[1][0] = dp[1][0];
        dp[0][1] = dp[0][1] + dp[1][0];
        dp[1][1] = dp[1][1] + dp[0][0];
//        dp[0][2] = dp[0][2] + dp[1][1], dp[0][2] + dp[1][0];
//        dp[1][2] = dp[1][2] + dp[0][1], dp[1][2] + dp[0][0];
//        dp[0][3] = dp[0][3] + dp[1][2], dp[0][3] +
        for (int i = 2; i <= n; i++) {
            dp[0][i] += max(dp[1][i-1], dp[1][i-2]);
            dp[1][i] += max(dp[0][i-1], dp[0][i-2]);
        }
        cout << max(dp[0][n], dp[1][n]) << "\n";
        t--;
    }

}