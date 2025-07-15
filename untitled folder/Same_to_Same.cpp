#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node(int v) {
        val = v;
        next = NULL;
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

bool areSame(Node* head1, Node* head2) {
    while (head1 != NULL && head2 != NULL) {
        if (head1->val != head2->val) return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    return (head1 == NULL && head2 == NULL);
}

int main() {
    Node* head1 = NULL;
    Node* tail1 = NULL;
    int val1;
    while (true) {
        cin >> val1;
        if (val1 == -1) {
            break;
        }
        insertAtTail(head1, tail1, val1);
    }
    Node* head2 = NULL;
    Node* tail2 = NULL;
    int val2;
    while (true) {
        cin >> val2;
        if (val2 == -1) {
            break;
        }
        insertAtTail(head2, tail2, val2);
    }

    

    if (areSame(head1, head2)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
