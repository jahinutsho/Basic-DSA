#include <iostream>
#include <vector>
using namespace std;

int main() {
  

    int n, q;
    cin >> n >> q;

    vector<long long> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    vector<long long> prefixSum(n + 1);
    prefixSum[1] = arr[1];

    for (int i = 2; i <= n; i++) {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        long long sum;
        if(l==1){sum = prefixSum[r];}
        else{sum = prefixSum[r] - prefixSum[l - 1];}
        cout << sum << endl;
    }

    return 0;
}
