#include <iostream>
#include<list>
using namespace std;
class myStack {
    
    public:
    list<int> arr;
void push(int val){
    arr.push_back(val);
}
void pop(){
    if(!arr.empty()){
        arr.pop_back();
    } else {
        cout << "Stack is empty" << endl;
    }
}
int top(){
    if(!arr.empty()){
        return arr.back();
    }
}
int size(){
    return arr.size();
}
bool isEmpty(){
    return arr.empty();
}
};
    

int main() {
    myStack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.top() << endl; // Should print
    s.pop();
    cout << "Top element after pop: " << s.top() << endl; // Should print 20
    cout << "Stack size: " << s.size() << endl; // Should print 2
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl; // Should print No
    

    return 0;
}