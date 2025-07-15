#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next = NULL;


    }};

void reverseList(Node*& temp) {
 if (temp == NULL) {
        return;
    }
    reverseList(temp->next);
    cout << temp->val << " ";
    
}
int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int n;
    while (cin >> n) {
        Node* newNode = new Node(n);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    Node* temp = head;
   reverseList(temp);

    return 0;
}