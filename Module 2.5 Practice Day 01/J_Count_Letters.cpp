#include <iostream>
#include <vector>
using namespace std;

int main() {
    string S;
    cin >> S;                   

    vector<int> count(26, 0);   

    for (char c : S) {          
        count[c - 'a']++;       
                                
    }

    for (int i = 0; i < 26; i++) {  
        if (count[i] > 0) {
            cout << char('a' + i) << " : " << count[i] << "\n";  
            
        }
    }

    return 0;                 
}
