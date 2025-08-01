#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class myStack {
public:
    Node* head;
    Node* tail;
    int size;

    myStack() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void pop() {
        if (tail == NULL) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node* temp = tail;
        tail = tail->prev;
        if (tail != NULL) {
            tail->next = NULL;
        } else {
            head = NULL;
        }
        delete temp;
        size--;
    }

    int top() {
        if (tail == NULL) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return tail->val;
    }

    int getSize() {
        return size;
    }

    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    int n;
    myStack s;
  
    cin >> n;

    for (int i = 0; i <= n; i++) {
        
        int x;
        cin >> x;
        s.push(x);
    }

    cout << "Stack size: " << s.getSize() << endl;
    while (!s.isEmpty()) {
        cout << "Top element: " << s.top() << endl;
        s.pop();
    }

    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
