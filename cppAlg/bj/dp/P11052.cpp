#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    int dp[1001];
    int price[1001];
    for (int i = 1; i <= n; i++) {
        cin >> price[i];
        dp[i] = price[i];
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <=i/2; j++) {
            dp[i] = max(dp[i], dp[j] + dp[i-j]);
        }
    }
    cout << dp[n];
    //1 1
    //1 2(2, 11 중 max)
    //1 3 2,2
    //1,4 2,3->(2 2 1)
    //1,5 2,
}