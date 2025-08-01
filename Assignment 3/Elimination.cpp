#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c == '1' && !st.empty() && st.top() == '0') {
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
        cout << (isValid(s) ? "YES" : "NO") << "\n";
    }
    return 0;
}
