#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<long long> prefixSum(n + 1);
    prefixSum[0] = 0;

    for (int i = 1; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }

    
    for (int i = n; i >= 1; i--) {
        cout << prefixSum[i] << " ";
    }
    cout << "\n";

    return 0;
}
