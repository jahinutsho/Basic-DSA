#include <iostream>
#include <queue>
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

int sum_of_Non_Leaf(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 0;
    return root->val + sum_of_Non_Leaf(root->left) + sum_of_Non_Leaf(root->right);
}

int main() {
    Node* root = input();
    cout << sum_of_Non_Leaf(root) << endl;
    return 0;
}
