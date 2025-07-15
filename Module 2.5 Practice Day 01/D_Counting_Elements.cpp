#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    int count = 0;
    for(int i = 0; i < n; ++i) {
        bool found = false;
        for(int j = 0; j < n; ++j) {
            if (a[j] == a[i] + 1) {
                found = true;
                break;  // no need to search further
            }
        }
        if (found) count++;
    }
    
    cout << count << "\n";
    return 0;
}
