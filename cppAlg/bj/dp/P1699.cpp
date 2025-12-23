#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int dp[100001] = {0};
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
//    dp[4] = 1; dp[3] + 1
//    dp[5] = 2;
//    dp[6] = 3;
//    dp[7] = 4;
//    dp[8] = 2;
//    dp[9] = 1;
//    dp[10] = 2;
//    dp[11] = 3;
//    dp[12] = dp[9] + dp[3], dp[4] + dp[8];
//    100,000 * 50,000
//    5,000,000,000
    for (int i = 4; i <= n; i++) {
        dp[i] = i;
        for (int j = 1; j <= 1000; j++) {
            if (j*j == i) {
                dp[i] = 1;
                break;
            } else {
                if (i - j*j < 0) break;
                dp[i] = min(dp[i], dp[i - j*j] + dp[j*j]);
            }
        }
        //cout << dp[i] << endl;
    }
    cout << dp[n];
}