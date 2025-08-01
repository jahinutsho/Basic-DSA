#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;
    Node(int val) {
        value = val;
        next = NULL;
    }
};

class Stack {
    Node* head = NULL;  
public:
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    int pop() {
        if (!head) return -1;
        int val = head->value;
        Node* temp = head;
        head = head->next;
        delete temp;
        return val;
    }
    int top() {
        return head ? head->value : -1;
    }
    bool isEmpty() {
        return head == NULL;
    }
};

class Queue {
    Node* head = NULL;   
    Node* tail = NULL;   
public:
    void push(int val) {
        Node* newNode = new Node(val);
        if (!tail) { 
            head = tail = newNode; 
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    int pop() {
        if (!head) return -1;
        int val = head->value;
        Node* temp = head;
        head = head->next;
        if (!head) tail = NULL;
        delete temp;
        return val;
    }
    int front() {
        return head ? head->value : -1;
    }
    bool isEmpty() {
        return head == NULL;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    Stack s;
    Queue q;

    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        s.push(val);
    }

    for (int i = 0; i < m; i++) {
        int val;
        cin >> val;
        q.push(val);
    }

    if (n != m) {
        cout << "NO" << endl;
        return 0;
    }

    while (!s.isEmpty() && !q.isEmpty()) {
        if (s.pop() != q.pop()) {
            cout << "NO" << endl;
            return 0;
        }
    }

    cout << "YES" << endl;
    return 0;
}
