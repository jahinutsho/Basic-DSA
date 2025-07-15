#include<list>
#include<vector>
#include<iostream>
using namespace std;    
int main(){
    list<int> l={1,2,3,4,5};
    list<int> l2(l); // Copy constructor
    list<int> l1(10,3);
    int arr[]={1,2,3,4,5};
    list<int> l3(arr,arr+5); // Initializing from array
    cout<< "Size of list: " << l1.size() << endl;
    for(int val : l3){
        cout << val << endl;
    }
    cout<<*l1.begin() << endl;
    cout<<*l1.end() << endl;
    cout<<l2.max_size();
    // Returns the maximum size of the list

    cout << l2.empty() << endl; // Check if the list is empty
    l2.push_back(6); // Add an element to the end
    l2.push_front(0); // Add an element to the front
    l2.pop_back(); // Remove the last element
    l2.pop_front(); // Remove the first element
    l2.remove(3); // Remove all occurrences of 3
    l2.sort(); // Sort the list
    l2.reverse(); // Reverse the list
    l2.clear(); // Clear the list
    cout << "List after operations: ";
    for(int val : l2){
        cout << val << " ";
    }
    cout << endl;
    l2.assign(l.begin(), l.end()); // Assign elements from another list
    cout << "List after assign: ";
    for(int val : l2){
        cout << val << " ";
    }
    cout << endl;
    l2.splice(l2.begin(), l); // Splice elements from another list
    cout << "List after splice: ";
    for(int val : l2){
        cout << val << " ";
    }
    cout << endl;
    l2.merge(l3); // Merge with another list
    cout << "List after merge: ";
    for(int val : l2){
        cout << val << " ";
    }   
    l1.erase(l1.begin(), l1.end()); // Erase all elements
    cout << "List after erase: ";
    for(int val : l1){
        cout << val << " "; }
    return 0;
}