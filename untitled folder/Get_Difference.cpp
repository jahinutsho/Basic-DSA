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

int findDiffrence(Node*& head) {
    int min = INT_MAX;
    int max = INT_MIN;
    for(Node* i = head; i != NULL; i = i->next) {
        if (i->val < min) {
            min = i->val;
        }
        if (i->val > max) {
            max = i->val;
        }
    }
    int difference = max - min;
    return difference;
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
    int diff = findDiffrence(head);

    cout << diff << endl;
    

    return 0;
}
