#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a = 0;
    cin >> n;
    vector<int> op(n + 1), op1(n + 1);
    op[0] = 0;
    op1[0] = 0;
    for(int i = 1; i <= n; i++) cin >> op[i];
    for(int i = 1; i <= n; i++) op1[i] = (op1[i - 1] + op[i]) % 7;
    vector<int> op2(7, -1);
    op2[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        if(op2[op1[i]] != -1) a = max(a, i - op2[op1[i]]);
        else op2[op1[i]] = i; 
    }
    cout << a << endl;
    return 0;
}