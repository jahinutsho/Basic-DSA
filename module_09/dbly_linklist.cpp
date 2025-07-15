#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val=val;
        this->next = NULL;
        this->prev = NULL;


    }};

void printListForward(Node* head) {
    Node* current = head;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}
void printListBackward(Node* tail) {
    Node* current = tail;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->prev;
    }
    cout << endl;
}
void insertAtHead(Node* &head, int val){
    Node* newNode = new Node(val);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    
}
void insertAtTail(Node* &tail, int val) {
    Node* newNode = new Node(val);
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;}

void insert_At_Any_Position(Node* &head, Node* &tail, int val, int pos) {
    Node* newNode = new Node(val);
    Node* temp = head;
        for (int i = 1; i < pos ; i++){
        
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;

}

void  deleteAtHead(Node* &head, Node* &tail) {
   Node* toDelete = head;
    head = head->next;
    delete toDelete;
    if(head == NULL){
        tail = NULL; 
        return;
    }
    head->prev = NULL;
}
void  deleteAtTail(Node* head,Node* &tail ) {
   Node* toDelete = tail;
    tail = tail->prev;
    delete toDelete;
    if(tail == NULL){
        head = NULL; 
        return;
    }
    tail->next = NULL;
}

void deleteAtAnyPosition(Node* &head, int pos) {
    
    Node* temp = head;
    for (int i = 1; i < pos; i++) {
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    delete toDelete;
    
  
}
int main() {
   Node* head = NULL;
    Node* tail = NULL;
    int val;
    while(true){
        cin>>val;
        if(val == -1) {
            break;
        }
        insertAtTail(tail, val);
        if(head == NULL) {
            head = tail;}
    }


    
 



    return 0;
}