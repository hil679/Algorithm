#include <iostream>
using namespace std;

bool checked[2600001];
int arr[14];
int n;
int sum = 0;

void checkWeight(int curTotalWeight, int curWeightIdx) {
    // if (curTotalWeight < 0) return; // < 1하면 안 됨. / curTotalWeight > sum  이 경우는 존재 불가능
    // 바로 return 하면 안 될 거 같음 -> 1번 추 빼고(반대편 그릇) 2번 추 더하면(내 그릇) 양수 나올 수도

    if (curTotalWeight >= 0) checked[curTotalWeight] = true;
    if (curWeightIdx > n) return;

    checkWeight(curTotalWeight, curWeightIdx+1);
    checkWeight(curTotalWeight + arr[curWeightIdx], curWeightIdx+1);
    checkWeight(curTotalWeight - arr[curWeightIdx], curWeightIdx+1);
}
int main() {
    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }

    checkWeight(0, 1);

    int ans = 0;
    for (int i = 1; i <= sum; i++) {
        if (!checked[i]) ans++;
    }
    cout << ans;
}