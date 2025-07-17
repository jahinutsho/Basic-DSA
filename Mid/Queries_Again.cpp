#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

void printLeftToRight(Node* head) {
    cout << "L -> ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

void printRightToLeft(Node* tail) {
    cout << "R -> ";
    Node* temp = tail;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->prev;
    }
    cout << endl;
}

int main() {
    int Q;
    cin >> Q;

    Node* head = NULL;
    Node* tail = NULL;

    for (int i = 0; i < Q; i++) {
        int index, val;
        cin >> index >> val;

        // Count current size
        int size = 0;
        Node* temp = head;
        while (temp != NULL) {
            size++;
            temp = temp->next;
        }

        // Invalid index
        if (index < 0 || index > size) {
            cout << "Invalid" << endl;
            continue;
        }

        Node* newNode = new Node(val);

        if (index == 0) {
            newNode->next = head;
            if (head != NULL) head->prev = newNode;
            head = newNode;
            if (tail == NULL) tail = newNode;
        }
        
        else if (index == size) {
            newNode->prev = tail;
            if (tail != NULL) tail->next = newNode;
            tail = newNode;
        }
        
        else {
            Node* temp = head;
            for (int j = 0; j < index - 1; j++) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }

       
        if (newNode->next == NULL) tail = newNode;

        
        printLeftToRight(head);
        printRightToLeft(tail);
    }

    return 0;
}
