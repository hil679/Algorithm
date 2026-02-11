#include <string>
#include <vector>
// #include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    char alpha[26]={};
    for (char sk : skip) {
        alpha[sk-'a'] = -1;
        // cout << sk - 'a' << " ";
    }

    for (char c : s) {
        int cur = c - 'a';
        int cIdx = index;
        // int skipCnt = 0;
        for (int i = 1; i <= cIdx; i++) {
            cout << (cur + i) % 26 << "\n";
            if (alpha[(cur + i) % 26] == -1) cIdx++;
        }
        // cur = (cur + index + skipCnt) % 26;
        cur = (cur + cIdx) % 26;
        // while (alpha[cur] == -1) cur = (cur+1) % 26;
        answer += (cur + 'a');

    }
    return answer;
}