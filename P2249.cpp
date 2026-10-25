#include <bits/stdc++.h>
using namespace std;

auto Find(vector<int>& op, int n, int l, int r)
{
    int i;
    if(n == op[l]) return l;
    if(r - l == 1 && n == op[r]) return r;
    if(r - l == 1 && n != op[l] && n != op[r]) return -2;
    int mid = (l + r) / 2;
    if(n <= op[mid]) i = Find(op, n, l, mid);
    if(n > op[mid]) i = Find(op, n, mid, r);
    return i;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> op(n);
    for(int i = 0; i < n; i++) cin >> op[i];
    for(int i = 0; i < m; i++)
    {
        int sz;
        cin >> sz;
        cout << Find(op, sz, 0, op.size() - 1) + 1 << " ";
    }
    return 0;
}