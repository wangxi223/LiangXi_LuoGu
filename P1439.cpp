#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> op1(n), op2(n), pos(n + 1);
    for(int i = 0; i < n; i++) cin >> op1[i], pos[op1[i]] = i;
    for(int i = 0; i < n; i++) cin >> op2[i];
    for(int i = 0; i < n; i++)
    {
        int k = op2[i];
        op2[i] = pos[k];
    }
    vector<int> op3;
    for(int i : op2)
    {
        auto k = lower_bound(op3.begin(), op3.end(), i);
        if(k == op3.end()) op3.push_back(i);
        else *k = i;
    }
    cout << op3.size() << endl;
    return 0;
}