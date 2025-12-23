#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int dp[1000] = {0};
    int nums[1000];

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        dp[i] = 1;
    }

    int m = dp[0];
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) dp[i]=max(dp[i],dp[j]+1);
        }
        //cout << dp[i] << " ";
        m = max(m, dp[i]);
    }
    cout << m;

}