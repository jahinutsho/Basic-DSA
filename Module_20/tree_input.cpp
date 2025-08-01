#include <iostream>
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
void levelOrder(Node* root) {
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
      
        Node* current = q.front();
        q.pop();
        
        
        cout << current->val << " ";

        
        if(current->left != NULL) {
            q.push(current->left);
        }
        if(current->right != NULL) {
            q.push(current->right);
        }
    
}};

int main() {
    cout << "Enter the root value: ";
    Node* root = input();
    cout << "Tree input completed." << endl;
    levelOrder(root);
    cout << endl;

    

    return 0;
}