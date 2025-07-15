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
void insertAtTail(Node*& head, Node* &tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        return;
    }
    
    tail->next = newNode;
    tail = tail->next;
}
void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* tail = new Node(30);
    head->next = second;
    second->next = tail;
    tail->next = NULL;
    insertAtTail(head,tail, 40);
    
    printList(head);    
    

    return 0;
}