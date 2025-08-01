#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) {
        val = v;
        left = NULL;
        right = NULL;
    }
};

Node* input() {
    int val;
    cin >> val;
    if (val == -1) return NULL;
    Node* root = new Node(val);
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        int leftVal, rightVal;
        cin >> leftVal;
        if (leftVal != -1) {
            current->left = new Node(leftVal);
            q.push(current->left);
        }
        cin >> rightVal;
        if (rightVal != -1) {
            current->right = new Node(rightVal);
            q.push(current->right);
        }
    }
    return root;
}

void collectLeaves(Node* root, vector<int>& leaves) {
    if (!root) return;
    if (!root->left && !root->right) { 
        leaves.push_back(root->val);
        return;
    }
    collectLeaves(root->left, leaves);
    collectLeaves(root->right, leaves);
}

int main() {
    Node* root = input();
    vector<int> leaves;
    collectLeaves(root, leaves);
    sort(leaves.begin(), leaves.end(), greater<int>());  
    for (int val : leaves) {
        cout << val << " ";
    }
    return 0;
}
