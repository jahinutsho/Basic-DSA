#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

     sort(arr.begin(), arr.end());

    bool hasDuplicate = false;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            hasDuplicate = true;
            break;
        }
    }

    if (hasDuplicate) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

    return 0;
}
