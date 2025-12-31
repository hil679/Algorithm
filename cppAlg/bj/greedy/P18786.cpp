//5 2
//9 3 5 7 1
//1 2 3 4 5
//
//9 3 5 4 5
//
//9 7 5 5 2
//차가 큰 순서로 정렬
//더 큰 쪽을 무조건 더하기 -> k 초과 차이나면 뒤에서부터 상대꺼 가져오기

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    int diffA = abs(a.first - a.second);
    int diffB = abs(b.first - b.second);
    return diffA > diffB;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); // 시간 초과 해결
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> pairs;
        vector<int> groupA(100000);
        vector<int> groupB(100000);
        for (int ability = 0; ability < n; ability++) {
            cin >> groupA[ability];
        }
        for (int ability = 0; ability < n; ability++) {
            cin >> groupB[ability];
        }
        for (int j = 0; j < n; j++) {
            pairs.push_back({groupA[j], groupB[j]});
        }

        sort(pairs.begin(), pairs.begin()+n, compare);
//        for (int j = 0; j < n; j++) {
//            cout << pairs[j].first << " " << pairs[j].second << "\n";
//        }

        long long ans = 0;
        int aNum = 0;
        int bNum = 0;

        /*
        1
        5 1
        13 30 2 13 3
        6 19 25 30 10
        이전 코드 -> 이 반례 때문에 불가능
        답 108 -> 나 101
        일단 max로 더하고, 인원차 초과하면 손해 작은 것부터 뒤집기로 변경 필요
        */
        vector<int> pickedA(100000);
        vector<int> pickedB(100000);
        for (int j = 0; j < n; j++) {
            int attack = pairs[j].first;
            int defense = pairs[j].second;
            if (attack > defense) {
                aNum++;
                ans += attack;
                pickedA[j] = 1;
            }
            else if (attack < defense) {
                bNum++;
                ans += defense;
                pickedB[j] = 1;
            }
            else ans += attack;
            //cout << ans << " " << j << " " << n << endl;
        }
        int diff = abs(aNum - bNum);
        int idx = aNum + bNum - 1;
        for (int d = diff; d > k;) {
            if (aNum > bNum && pickedA[idx] == 1) {
                ans -= pairs[idx].first;
                ans += pairs[idx].second;
                d -= 2;
            }
            else if (aNum < bNum && pickedB[idx] == 1) {
                ans += pairs[idx].first;
                ans -= pairs[idx].second;
                d -= 2;
            }

            idx--;
        }
        cout << ans << "\n";
    }
}
