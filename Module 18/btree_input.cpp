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

    Node* input(){
        int val;
        cin>> val;
        Node* root = new Node(val);
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            // ber kore ante hobe
            Node* current = q.front();
            q.pop();
            // kaj
            int leftVal, rightVal;
            cin >> leftVal >> rightVal;
            Node* myLeft, *myRight; 
            if(leftVal == -1) {
                myLeft = NULL;
            } else {
                myLeft = new Node(leftVal);  
            }
            if(rightVal == -1) {
                myRight = NULL;
            } else {
                myRight = new Node(rightVal);
            }
           current->left = myLeft;
           current->right = myRight;
              if(myLeft != NULL) {
                q.push(myLeft);
            }
            if(myRight != NULL) {
                q.push(myRight);
            }
        }
        return root;
        
    };
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
    cout << "Enter the values for the tree (-1 for null): ";
    Node* root = input();
   
    
    cout << "Level order traversal: ";
    levelOrder(root);
    cout << endl;
    

    return 0;
}