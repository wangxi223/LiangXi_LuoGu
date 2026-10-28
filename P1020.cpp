#include <algorithm>
#include <bits/stdc++.h>
#include <functional>
#include <vector>
using namespace std;

int main()
{
    vector<int> n;
    int ls;
    while(cin >> ls) n.push_back(ls);
    vector<int> op, op1;
    for(int i : n)
    {
        auto u = upper_bound(op.begin(), op.end(), i, greater<int>());
        if(u == op.end()) op.push_back(i);
        else *u = i;
    }
    for(int i : n)
    {
        auto u = lower_bound(op1.begin(), op1.end(), i);
        if(u == op1.end()) op1.push_back(i);
        else *u = i;
    }
    cout << op.size() << endl << op1.size() << endl;
    return 0;
}