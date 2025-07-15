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

void deleteNode(Node*& head,int indx) {
    Node* temp = head;
    for(int i =1; i<indx;i++){
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    delete toDelete;
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
    deleteNode(head, 2); // Deleting the node at index 3
    printList(head);    

    return 0;
}