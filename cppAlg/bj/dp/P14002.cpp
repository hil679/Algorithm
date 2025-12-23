#include <iostream>
#include <stack>
using namespace std;
int main() {
    int n;
    cin >> n;
    int dp[1000] = {0};
    int nums[1000];
    int connection[1001] = {0};
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        dp[i] = 1;
    }

    int m = dp[0];
    int m_idx = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                if (dp[i] < dp[j] + 1) {
                    dp[i]=dp[j]+1;
                    connection[i] = j;
                }
            }
        }
        //cout << dp[i] << " ";
        if (m < dp[i]) {
            m = dp[i];
            m_idx = i;
        }
    }
    cout << m << endl;

    int cur = 0;
    stack<int> s;
    while (cur < m) {
        s.push(nums[m_idx]);
        cur++;
        //cout << m_idx << " ";
        m_idx = connection[m_idx];
    }
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}