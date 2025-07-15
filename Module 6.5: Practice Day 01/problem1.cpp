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
    Node* head = new Node(2);
    Node* a = new Node(1);
    Node* b = new Node(5);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(8);
    Node* f = new Node(9);
    head->next = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    e->next = f;
    f->next = NULL;

    int count=0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    cout << "The length of the linked list is: " << count << endl;
    

    return 0;
}