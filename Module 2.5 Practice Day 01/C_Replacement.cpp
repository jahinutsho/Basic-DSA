#include <iostream>
#include <vector>  // Add this line
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if(arr[i] < 0) {
            arr[i] = 2;
        }       
        else if(arr[i] > 0) {
            arr[i] = 1;
        }
        cout << arr[i] << " ";
    }
 
    return 0;
}
