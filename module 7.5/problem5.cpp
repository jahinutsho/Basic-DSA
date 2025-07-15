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
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

int findMax(Node* head) {
    if (head == NULL) return INT_MIN; // Empty list

    int maxVal = head->val;
    Node* temp = head->next;
    while (temp != NULL) {
        if (temp->val > maxVal) {
            maxVal = temp->val;
        }
        temp = temp->next;
    }
    return maxVal;
}

int main() {
    Node* head = NULL;
    Node* tail = NULL;
    int n;

    while (true) {
        cin >> n;
        if (n == -1) break;
        insertAtTail(head, tail, n);
    }

    int maxValue = findMax(head);
    cout << "Maximum value: " << maxValue << endl;

    return 0;
}
