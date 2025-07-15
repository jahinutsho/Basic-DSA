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

void insertAtHead(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    if (tail == NULL) tail = newNode;
}

void insertAtPosition(Node*& head, Node*& tail, int idx, int val) {
    if (idx == 0) {
        insertAtHead(head, tail, val);
        return;
    }

    Node* newNode = new Node(val);
    Node* temp = head;
    for (int i = 1; i < idx && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) return;

    newNode->next = temp->next;
    temp->next = newNode;

    if (newNode->next == NULL) {
        tail = newNode;
    }
}

int size(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int n;

    // Initial list input
    while (cin >> n && n != -1) {
        insertAtTail(head, tail, n);
    }

    int pos, val;

    
    while (cin >> pos >> val) {
        int sz = size(head);
        if (pos == 0) {
            insertAtHead(head, tail, val);
            printList(head);
        }
        else if (pos == sz) {
            insertAtTail(head, tail, val);
            printList(head);
        }
        else if (pos > sz) {
            cout << "Invalid" << endl;
        }
        else {
            insertAtPosition(head, tail, pos, val);
            printList(head);
        }
    }

    return 0;
}
