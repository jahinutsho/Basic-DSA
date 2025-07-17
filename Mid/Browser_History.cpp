#include <iostream>
using namespace std;

class Node {
public:
    string val;
    Node* next;
    Node* prev;

    Node(string val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insertAtTail(Node*& head, Node*& tail, string val) {
    Node* newNode = new Node(val);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}
int main() {
    string s;
    Node* head = NULL;
    Node* tail = NULL;

    
    while (cin >> s) {
       
        if(s== "end") {
            break;
        }
        insertAtTail(head, tail, s);
    }

    int q;
    cin >> q;

    string command, address;
    Node* current = head;

    while (q--) {
        cin >> command;
        if (command == "visit") {
            cin >> address;
            Node* temp = head;
            bool found = false;

            while (temp != NULL) {
                if (temp->val == address) {
                    current = temp;
                    cout << current->val << endl;
                    found = true;
                    break;
                }
                temp = temp->next;
            }

            if (!found) {
                cout << "Not Available" << endl;
            }

        } else if (command == "next") {
            if (current->next != NULL) {
                current = current->next;
                cout << current->val << endl;
            } else {
                cout << "Not Available" << endl;
            }

        } else if (command == "prev") {
            if (current->prev != NULL) {
                current = current->prev;
                cout << current->val << endl;
            } else {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}
