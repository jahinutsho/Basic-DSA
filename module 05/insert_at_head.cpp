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

void insertAtHead(Node*& head, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
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
    Node* third = new Node(30);
    head->next = second;
    second->next = third;
    third->next = NULL;
    
    insertAtHead(head, 5);
    insertAtHead(head, 1);
    printList(head);

    return 0;
}