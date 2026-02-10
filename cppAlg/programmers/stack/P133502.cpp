#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient) {
    int ans = 0;
    stack<int> s;
    for (int ingre : ingredient) {
        if (ingre == 1 && s.size() >= 3) {
            int complete = 1;
            vector<int> popIngre;
            for (int j = 3; j > 0; j--) {
                if (s.top() == j) {
                    popIngre.push_back(s.top());
                    s.pop();
                }
                else {
                    for (int i = popIngre.size() - 1; i >= 0; i--) s.push(popIngre[i]);
                    s.push(ingre);
                    complete = 0;
                    break;
                }

            }

            if (complete == 1) ans++;
        } else {
            s.push(ingre);
        }
    }
    return ans;
}