#include <string>
#include <vector>
// #include <iostream>

using namespace std;

int solution(string s) {
    int answer = 0;
    int first = 1;
    int other = 0;
    char firstChar = s[0];
    if (s.length() == 1) return 1;
    for (int i = 1; i < s.length(); i++) {

        if (s[i] == firstChar) first++;
        else other++;

        if (first == other) {
            answer++;
            i++;
            first = 1;
            other = 0;
            // cout << firstChar << " ";
            if (i == s.length() - 1) {
                answer++;
                break;
            }
            firstChar = s[i];
        }
    }
    // cout << firstChar << " ";
    if (other != 0 || first != 1) answer++;
    return answer;
}