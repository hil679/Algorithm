#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

/*
예시
arr = [1,2,2,2,3], x=2
정답(첫 >=2)은 인덱스 1

초기: L=0, R=5 (unknown=[0,5))

mid=2, arr[2]=2 (True) → R=2
이제 [2,5)는 True로 “확정”, unknown=[0,2)

mid=1, arr[1]=2 (True) → R=1
이제 [1,5)는 True 확정, unknown=[0,1)

mid=0, arr[0]=1 (False) → L=1
unknown=[1,1) 끝 → L==R==1 (정답)

보이지? R=mid 할 때마다 mid가 “빠지는” 게 아니라 True 경계가 mid로 당겨지는 거야.
*/
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int arr[10000];
    for (int i =0; i < n; i++) {
        cin >> arr[i];
    }
    long long left = 1, right = (long long)INT_MAX+1;
    long long mid, ans = 0;
    long long num;
    while (left < right) {
        mid = left +(right - left)/2;
        num = 0;
        for (int i =0; i < n; i++) {
            num += (arr[i] / mid);
            // if (num >= m) break;
        }
        if (num < m) right = mid;
        else if (num >= m) {
            left = mid+1;
            ans = mid;
        }
       // cout << mid << endl;
    }
    cout << ans;
}