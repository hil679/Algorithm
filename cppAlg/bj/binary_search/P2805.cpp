#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int arr[1000000];
    for (int i =0; i < n; i++) {
        cin >> arr[i];
    }
//log 2000000000 = 10log2
//1,000,000 * 10log2 ->
    int left = 0; int right = 2000000000;
    while (left <= right) {
        long tree = 0;
        int mid = left + (right - left)/2;
        for (int i =0; i < n; i++) {
            if (arr[i] - mid > 0) tree += (arr[i] - mid);
        }
        if (tree < m) right = mid-1;
        else if (tree > m) left = mid+1;
        else {left = mid;
            cout << left;
            return 0;
        }
    }
    cout << left-1;
}