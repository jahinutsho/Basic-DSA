#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val) {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
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
        Node* f = q.front();
        q.pop();
        int l, r;
        if (!(cin >> l >> r)) break;
        if (l != -1) {
            f->left = new Node(l);
            q.push(f->left);
        }
        if (r != -1) {
            f->right = new Node(r);
            q.push(f->right);
        }
    }
    return root;
}


void leftside(Node* root) {
    if (!root) return;
    if (!root->left && !root->right) {
        cout << root->val << " ";
        return;
    }
    if (root->left) leftside(root->left);
    else if (root->right) leftside(root->right);    
    cout << root->val << " ";
}


void rightside(Node* root) {
    if (!root) return;

    if (!root->left && !root->right) {
        cout << root->val << " ";
        return;
    }
    cout << root->val << " ";
    if (root->right) rightside(root->right);
    else if (root->left) rightside(root->left);
}

int main() {
    Node* root = input();
    if (!root) return 0;
    leftside(root->left);
    cout << root->val << " ";
    rightside(root->right);

    return 0;
}
