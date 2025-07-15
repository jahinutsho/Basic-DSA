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


int findIndex(Node* head, int x) {
    int index = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->val == x) {
            return index;
        }
        temp = temp->next;
        index++;
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        Node* head = NULL;
        Node* tail = NULL;
        int val;

        
        while (true) {
            cin >> val;
            if (val == -1) break;
            insertAtTail(head, tail, val);
        }

        int X;
        cin >> X;

        int result = findIndex(head, X);
        cout << result << endl;

        
    }

    return 0;
}
