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

int count(Node* head) {
    Node* temp = head;
    int count = 0;  
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;}

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



int main() {
    Node* head1 = NULL;
    Node* tail1 = NULL;
    Node* head2 = NULL;
    Node* tail2 = NULL;
    int n;
    while (true) {
        cin >> n;
        if (n == -1) {
            break;
        }
        insertAtTail(head1, tail1, n);
    }
    while (true) {
        cin >> n;
        if (n == -1) {
            break;
        }
        insertAtTail(head2, tail2, n);
    }
   
    int count1 = count(head1);
    int count2 = count(head2);
    if (count1 != count2) {
        cout << "NO" << endl;
        return 0;
    }else{
        cout << "YES" << endl;
        return 0;
    }

    return 0;
}
