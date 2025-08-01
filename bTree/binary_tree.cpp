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
void printPreorder(Node* root) {
    if (root == NULL) return;
    cout << root->val << " ";
    printPreorder(root->left);
    printPreorder(root->right);
}
void printPostorder(Node* root) {
    if (root == NULL) return;
    printPostorder(root->left);
    printPostorder(root->right);
    cout << root->val << " ";
}

void printInorder(Node* root) {
    if (root == NULL) return;
    printInorder(root->left);
    cout << root->val << " ";
    printInorder(root->right);
}

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
    cout << "Preorder: ";
    printPreorder(root);
    cout << "\nPostorder: ";
    printPostorder(root);
    cout << "\nInorder: ";
    printInorder(root);
    cout << endl;

    

    return 0;
}