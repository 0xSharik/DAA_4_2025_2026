#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    vector<int> arr = {2,5,7,1,4,8,9,7};
    int n = arr.size();

    vector<int> dp(n, 0);
    int result = INT_MIN;

  
    for(int i = n - 2; i >= 0; i--) {
        int count = 0;

        for(int j = i + 1; j < n; j++) {
            if(arr[j] > arr[i]) {
                count++;
            }
        }

        dp[i] = count;
        result = max(result, dp[i]);
    }

    cout << result;
    return 0;
}
