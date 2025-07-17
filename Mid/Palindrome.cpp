#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val=val;
        this->prev = NULL;
        this->next = NULL;


    }};
void insertAtTail(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    
}
     


int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int n;
    while (cin >> n) {
        if (n == -1) {
            break;
        }
        insertAtTail(head, tail, n);
    }
    
    Node* left = head;
    Node* right = tail;
    bool isPalindrome = true;
    while (left != NULL && right != NULL && left != right && left->prev != right) {
        if (left->val != right->val) {
            isPalindrome = false;
            break;
        }
        left = left->next;
        right = right->prev;
    }
    if (isPalindrome) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;    }

    return 0;
}