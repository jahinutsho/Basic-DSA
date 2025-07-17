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

void reverseList(Node*& head,Node*& temp,Node *& tail) {
    
 if (temp->next == NULL) {
        head = temp; 
        return;
    }
    reverseList(head,temp->next);
    temp->next->next = temp; 
    temp->next = NULL;
    tail = temp; 
    
}
void print(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
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
   node* temp = head;

   reverseList(head,temp ,tail);

    cout << "Reversed Linked List: ";
   print(head);

    return 0;
}