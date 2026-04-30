#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    vector<int> arr = {2,5,7,1,4,8,9,7};
    int size = arr.size();
    int result = INT_MIN;

    for(int i = 0; i < size - 1; i++) {
        int temp = 0; 
        for(int j = i + 1; j < size; j++) {
            if(arr[i] < arr[j]) {
                temp++;
            }
        }
        if(result < temp) result = temp;
    }

    cout << result;
    return 0;
}

//folder name: lab external