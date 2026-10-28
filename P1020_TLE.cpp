#include <bits/stdc++.h>
using namespace std;

int main()
{
    int ls;
    vector<int> n;
    while(cin >> ls) n.push_back(ls);
    vector<int> dp1(n.size(), 1);
    for(int i = 0; i < n.size(); i++)
    for(int j = 0; j < i; j++)
    {
        if(n[i] <= n[j]) dp1[i] = max(dp1[i], dp1[j] + 1);
    }
    sort(dp1.begin(), dp1.end());
    cout << dp1[dp1.size() - 1] << endl;
    vector<int> dp2(n.size(), 1);
    for(int i = 0; i < n.size(); i++)
    for(int j = 0; j < i; j++)
    {
        if(n[i] > n[j]) dp2[i] = max(dp2[i], dp2[j] + 1);
    }
    sort(dp2.begin(), dp2.end());
    cout << dp2[dp2.size() - 1] <<  endl;
    return 0;
}