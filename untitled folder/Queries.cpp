#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        next = NULL;
    }
};


void insertAtHead(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    if (tail == NULL) {
        tail = newNode;
    }
}


void insertAtTail(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void deleteAtIndex(Node*& head, Node*& tail, int idx) {
    if (head == NULL) return;

    if (idx == 0) {
        Node* del = head;
        head = head->next;
        delete del;
        if (head == NULL) {
            tail = NULL;
        }
        return;
    }

    Node* temp = head;
    for (int i = 0; i < idx - 1; i++) {
        if (temp == NULL || temp->next == NULL) return;
        temp = temp->next;
    }

    Node* del = temp->next;
    if (del == NULL) return;

    temp->next = del->next;
    if (del == tail) {
        tail = temp;
    }
    delete del;
}




void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    int Q;
    cin >> Q;

    Node* head = NULL;
    Node* tail = NULL;

    while (Q--) {
        int X, V;
        cin >> X >> V;

        if (X == 0) {
            insertAtHead(head, tail, V);
        } else if (X == 1) {
            insertAtTail(head, tail, V);
        } else if (X == 2) {
            deleteAtIndex(head, tail, V);
        }

        printList(head);
    }

    return 0;
}
