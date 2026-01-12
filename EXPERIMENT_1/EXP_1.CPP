#include <bits/stdc++.h>

using namespace std;
using namespace std::chrono;

int depth = 0, operation = 0;

void complexRec(int n, int newdepth) {
    if (n <= 2) {
        depth = max(depth, newdepth); 
        return;
    }

    int p = n;
    while (p > 0) {
        vector<int> temp(n);
        for (int i = 0; i < n; i++) {
            temp[i] = i ^ p;
            operation++;
        }
        p >>= 1;
        operation++;
    }

    vector<int> small(n);
    for (int i = 0; i < n; i++) {
        small[i] = i * i;
        operation++;
    }

    if (n % 3 == 0) {
        operation++;
        reverse(small.begin(), small.end());
    } else {
        operation++;
        reverse(small.begin(), small.end());
    }

    
    complexRec(n / 2, newdepth + 1);
    complexRec(n / 2, newdepth + 1);
    complexRec(n / 2, newdepth + 1);
}

int main() {
    int n = 10;
    auto start = high_resolution_clock::now();
    complexRec(n, 1);
    auto end =  high_resolution_clock::now();
    auto duration =  duration_cast<milliseconds > (end-start);
    cout << "operation : " << operation << " depth : " << depth<<endl;
   cout << "time taken (ms): " << duration.count(); 
}

// RECURRENCE RELATION FOR THIS :  T(n) = 3T(n/2)  + n(log(n) + 1)

// TIME COMPLEXITY : n^log2 3 ( n to the power log 3 base 2 ) 
// it is case 1 master theorem 