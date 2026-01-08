#include <iostream>
using namespace std;

pair<char, char> node[26];
void preorder(char root) {
    if (root == '.') return;
    cout << root;
    preorder(node[root-'A'].first);
    preorder(node[root-'A'].second);
}
void inorder(char root) {
    if (root == '.') return;
    inorder(node[root-'A'].first);
    cout << root;
    inorder(node[root-'A'].second);
}
void postorder(char root) {
    if (root == '.') return;
    postorder(node[root-'A'].first);
    postorder(node[root-'A'].second);
    cout << root;
}

int main() {
    int n;
    cin >> n;
    char parent, left, right;
    for (int i = 0; i <n; i++) {
        cin >> parent >> left >> right;
        node[parent-'A'].first=left;
        node[parent-'A'].second=right;
    }
    preorder('A');
    cout<<"\n";
    inorder('A');
    cout<<"\n";
    postorder('A');
}