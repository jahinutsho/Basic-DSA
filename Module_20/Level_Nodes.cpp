#include <iostream>
#include <queue>
#include <vector>
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

void printLevel(Node* root, int k) {
    if (!root) {
        cout << "Invalid";
        return;
    }
    queue<Node*> q;
    q.push(root);
    int level = 0;
    while (!q.empty()) {
        int size = q.size();
        if (level == k) {
            for (int i = 0; i < size; i++) {
                cout << q.front()->val << (i == size - 1 ? "" : " ");
                q.pop();
            }
            return;
        }
        for (int i = 0; i < size; i++) {
            Node* node = q.front();
            q.pop();
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        level++;
    }
    cout << "Invalid";
}

int main() {
    Node* root = input();
    int k;
    cin >> k;
    printLevel(root, k);
    return 0;
}
