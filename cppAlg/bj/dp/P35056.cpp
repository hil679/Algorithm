#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll NEG = -(1LL<<60);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<ll> A(N+1), B(N); // A[1..N], B[1..N-1]
    for (int i = 1; i <= N; i++) cin >> A[i];
    for (int i = 1; i <= N-1; i++) cin >> B[i];

    /*
    행 인덱스 k: 1~i 구간에서 지은 타워 개수 (=비용)
열/상태 인덱스 s: i번 칸의 상태
s = 0 : i번 칸에 타워 없음
s = 1 : i번 칸에 타워 있음, 왼쪽(i-1)과 연결 안 됨 (→ i+1과 연결 가능)
s = 2 : i번 칸에 타워 있음, 왼쪽(i-1)과 연결 됨 (→ i+1과 연결 불가)
값 dp[k][s]: 위 조건을 만족하는 배치들 중 가치의 최댓값

ndp[k][s] = “1..i+1까지 결정했을 때, 타워 k개, (i+1)번 상태가 s인 배치의 최대 가치”
    */
    vector<array<ll,3>> dp(N+1), ndp(N+1);
    for (int k = 0; k <= N; k++) dp[k] = {-1, -1, -1};

    // i=1 초기화
    dp[0][0] = 0;        // 1번에 타워 안 지음
    dp[1][1] = A[1];     // 1번에 타워 지음(연결 없음)

    for (int i = 1; i <= N-1; i++) { // i 번째 타워까지 고려
        for (int k = 0; k <= N; k++) ndp[k] = {NEG, NEG, NEG};

        for (int k = 0; k <= i; k++) {
            for (int s = 0; s < 3; s++) {
                ll cur = dp[k][s]; // i번째 타워까지 고려했을 때 k개 세웠을 때 각 s마다 최대 value
                if (cur == -1) continue;

                // 1) i+1에 타워 안 짓기(안 지으니까 타워는 k개) -> 상태 0
                ndp[k][0] = max(ndp[k][0], cur);

                // 2) i+1에 타워만 짓기(지으니까 타워는 k+1개) -> 상태 1
                ndp[k+1][1] = max(ndp[k+1][1], cur + A[i+1]);

                // 3) i와 i+1 연결(통로) -> i가 상태 1일 때만 가능
                if (s == 1) {
                    ndp[k+1][2] = max(ndp[k+1][2], cur + A[i+1] + B[i]);
                }
            }
        }
        dp.swap(ndp);
    }

    for (int cost = 1; cost <= N; cost++) {
        ll ans = max({dp[cost][0], dp[cost][1], dp[cost][2]});
        cout << ans << "\n";
    }
    return 0;
}
