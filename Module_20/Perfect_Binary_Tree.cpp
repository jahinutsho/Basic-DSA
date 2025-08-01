#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int v) {
        val = v;
        left = right = NULL;
    }
};


Node* input(){
    int val;
    cin>>val;
    Node* root = new Node(val);\
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* f = q.front();
        q.pop();
        int l,r;
        cin>>l>>r;
        Node* myLeft, *myRight;
        if(l == -1) myLeft = NULL;
        else myLeft = new Node(l);
        if(r == -1) myRight = NULL;
        else myRight = new Node(r);
        f->left = myLeft;
        f->right = myRight;

        if(f->left) {
            f->left = new Node(l);
            q.push(f->left);
        }
        if(f->right) {
            f->right = new Node(r);
            q.push(f->right);   }
    }
    return root;
}


int countNodes(Node* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}


int maxDepth(Node* root) {
    if (!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int main() {
    Node* root = input();
    int nodes = countNodes(root);
    int depth = maxDepth(root);
    int expectedNodes = pow(2, depth) - 1;

    if (nodes == expectedNodes) cout << "YES";
    else cout << "NO";

    return 0;
}
