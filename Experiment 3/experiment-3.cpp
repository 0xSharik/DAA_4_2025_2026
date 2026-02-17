#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    unordered_map<int,int> mp;

    int sum = 0;
    int maxLen = 0;
    mp[0] = -1;

    for(int i = 0; i < n; i++)
    {
        char ch;
        cin >> ch;

        if(ch == 'P')
            sum += 1;
        else
            sum -= 1;

        if(mp.find(sum) != mp.end())
        {
            int len = i - mp[sum];
            maxLen = max(maxLen, len);
        }
        else
        {
            mp[sum] = i;
        }
    }

    cout << maxLen;

    return 0;
}
