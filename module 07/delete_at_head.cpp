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

void deleteAtHead(Node*& head) {
    if (head == NULL) {
        return; 
    }
    Node* temp = head; 
    head = head->next; 
    delete temp; 
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

    printList(head);
    deleteAtHead(head);
    printList(head);    

    return 0;
}