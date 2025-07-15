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

int main() {
    Node* head = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);  
    head->next = second;
    second->next = third;
    third->next = NULL;
    
    Node* temp = head;
    while(temp != NULL) {
        cout<<temp->val<<endl;
        temp = temp->next;
    }
    


    

    return 0;
}