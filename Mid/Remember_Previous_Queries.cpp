#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
    int Q;
    cin >> Q;

    list<int> l1;

    while (Q--) {
        int X;
        long long V; 
        cin >> X >> V;

        if (X == 0) {
            l1.push_front(V);
        }
        else if (X == 1) {
            l1.push_back(V);
        }
        else if (X == 2) {
            if (V < l1.size()) {
                auto it = l1.begin();
                for (int i = 0; i < V; i++) {
                    it++;
                }
                l1.erase(it);
            }
        }

     
        cout << "L -> ";
        for (int val : l1) {
            cout << val << " ";
        }
        cout << endl;

        
        cout << "R -> ";
        vector<int> temp;
        for (int val : l1) {
            temp.push_back(val);
        }
        for (int i = temp.size() - 1; i >= 0; i--) {
            cout << temp[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
