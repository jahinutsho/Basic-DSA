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
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    
    // Step 1: Count the number of nodes
    int count = 0;
    Node* tmp = head;
    while (tmp != NULL) {
        count++;
        tmp = tmp->next;
    }

    // Step 2: Find the middle element(s)
    tmp = head;
    int mid = count / 2;
    for (int i = 0; i < mid - (count % 2 == 0 ? 1 : 0); i++) {
        tmp = tmp->next;
    }

    // Step 3: Print the middle element(s)
    cout << "Middle element(s): ";
    if (count % 2 == 0) {
        cout << tmp->val << " " << tmp->next->val << endl;
    } else {
        cout << tmp->val << endl;
    }

    return 0;
}