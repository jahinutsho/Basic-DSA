#include <iostream>
#include<list>
using namespace std;

int main() {
    list<int> l1;
    int n;
    while (cin >> n) {
        if (n == -1) {
            break; 
        }
        l1.push_back(n);
    }
    l1.sort();
    l1.unique();
    for(auto val : l1) {
        cout << val << " ";
    }

    

    return 0;
}