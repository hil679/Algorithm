#include <iostream>
#include <algorithm>
using namespace std;

// x가 처음 등장하는 위치(첫 >= x)
int firstPos(const int* arr, int n, int x) {
    int l = 0, r = n; // [l, r)
    while (l < r) {
        // l + r 자체가 int 범위를 넘어가면(큰 값이면) 음수로 튀거나 이상한 값이 될 수 있음
        int mid = l + (r - l) / 2;
        /*
          P(mid)가 True면: mid도 후보니까 오른쪽을 줄여야 함 → r = mid
          P(mid)가 False면: mid까지는 전부 False니까 왼쪽을 올려야 함 → l = mid + 1
        */
        if (arr[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return l; // n이면 없음
}

// x가 마지막으로 등장하는 위치(마지막 <= x)
int lastPos(const int* arr, int n, int x) {
    int l = 0, r = n; // [l, r)
    while (l < r) {
        int mid = l + (r - l) / 2;
        /*
          T T F F F 니까
          P(mid)가 True면: mid는 아직 OK, 더 오른쪽에 True가 있을 수 있음 → l = mid + 1
          P(mid)가 False면: mid부터는 안 됨 → r = mid
          1, 2, 2, 2, 3, 3
          x = 2
          mid = 2 -> l = 3, r = 5
          mid = 4 -> l = 3, r = 4
          mid = 3 -> l = 4, r = 4
        */
        if (arr[mid] <= x) l = mid + 1;
        else r = mid; // x < arr[mid]
    }
    return l - 1; // -1이면 없음
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n;
    static int arr[500000];
    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr, arr + n);

    cin >> m;
    while (m--) {
        int x;
        cin >> x;

        int first = firstPos(arr, n, x);
        if (first == n || arr[first] != x) { // 존재하지 않음
            cout << 0 << ' ';
            continue;
        }
        int last = lastPos(arr, n, x);
        cout << (last - first + 1) << ' ';
    }
    return 0;
}
