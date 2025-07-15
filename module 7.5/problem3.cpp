#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void printList(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void sortedList(Node*& head) {
    for(Node* i = head; i != NULL; i = i->next) {
        for(Node* j = i->next; j != NULL; j = j->next) {
            if(i->val > j->val) {
                swap(j->val, i->val);
            }
        }
    }
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int n;
    while (true) {
        cin >> n;
        if (n == -1) {
            break;
        }
        insertAtTail(head, tail, n);
    }
    sortedList(head);
    printList(head);

    return 0;
}
