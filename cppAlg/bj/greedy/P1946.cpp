#include <iostream>
#include <algorithm>
using namespace std;

struct Rank {
    int application;
    int interview;
};

bool compare(Rank a, Rank b) {
    return a.application < b.application;
}

int main() {
    int t, n;
    cin >> t;
    while (t > 0) {
        Rank arr[100001];
        cin >> n;
        int ans = 1;
        for (int i = 1; i <= n; i++) {
            cin >> arr[i].application >> arr[i].interview;
        }

        sort(arr+1, arr+n+1, compare);
        int interviewRank = arr[1].interview;
        for (int i = 2; i <= n; i++) {
            if (interviewRank > arr[i].interview) {
                ans++;
                interviewRank = arr[i].interview;
            }
        }
        cout << ans << "\n";
        t--;
    }
}