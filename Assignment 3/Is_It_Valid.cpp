#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (!st.empty() && st.top() != c) {
            st.pop();  
        } else {
            st.push(c); 
        }
    }
    return st.empty();
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << (isValid(s) ? "YES" : "NO") << endl;
    }
    return 0;
}
