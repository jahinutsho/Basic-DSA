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


void insertAtTail(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

void removeDuplicates(Node*& head) {
    bool freq[1001] = {false};

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL) {
        if (freq[temp->val]) {
            prev->next = temp->next;
            delete temp;
            temp = prev->next;
        } else {
            freq[temp->val] = true;
            prev = temp;
            temp = temp->next;
        }
    }
}



void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << "\n";
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
    removeDuplicates(head);
    printList(head);

    return 0;
}
