#include <iostream>
#include <queue>
using namespace std;
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node(int val){
        this->val=val;
        this->left = NULL;
        this->right = NULL;


    }};
void levelOrder(Node* root) {
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        // ber kore ante hobe
        Node* current = q.front();
        q.pop();
        
        // kaj
        cout << current->val << " ";

        // left and right children ke queue te add korte hobe
        if(current->left != NULL) {
            q.push(current->left);
        }
        if(current->right != NULL) {
            q.push(current->right);
        }
    
}};

int main() {
    Node* root = new Node(1);
    Node* a = new Node(2);
    Node* b = new Node(3);
    Node* c = new Node(4);
    Node* d = new Node(5);
    Node* e = new Node(6);

    root->left = a;
    root->right = b;
    a->left = c;
    a->right = d;
    b->left = e;
    cout << "Level order traversal: ";
    levelOrder(root);
    cout << endl;

    

    return 0;
}