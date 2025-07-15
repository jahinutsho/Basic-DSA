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

void insertAtPosition(Node*& head, int idx, int val) {
    Node* newNode = new Node(val);
    Node* temp = head;
    for(int i=1; i<idx; i++){
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;

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

    insertAtPosition(head, 2, 25); 
    

    printList(head);


    

    return 0;
}