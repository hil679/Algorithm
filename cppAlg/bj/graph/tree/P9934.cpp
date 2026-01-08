#include <iostream>
#include <cmath>
using namespace std;


/* complete binary tree*/
int tree[1024];
int nodeNum;
void printTree(int idx, int level) {
    int gap = pow(2, level+1);
    for (int i = idx; i <= nodeNum; i+=gap) {
       cout << tree[i] << " ";
    }
    cout << endl;
    printTree(pow(2, level-1), level-1);
}
int main() {
    int k;
    cin >> k;
    //입력이 inorder, root는 2^(n-1) -1
    nodeNum = pow(2, k) -1;
    for (int i =1; i <= nodeNum; i++) {
        cin >> tree[i];
    }
    tree(pow(2,  k-1), k-1);
}