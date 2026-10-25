#include <bits/stdc++.h>
#include <vector>
using namespace std;

int l1, n, m, l = 0, r = 0;

bool check(vector<int>& op, int mid)
{
    int ans = 0, p = 0;
    for(int i = 0; i < n; i++)
    {
        if(op[i] - p < mid) ans++;
        else p = op[i];
    }
    if(l1 - p < mid) ans++;
    return ans <= m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> l1 >> n >> m;
    r = l1;
    vector<int> op(n);
    for(int i = 0; i < n; i++) cin >> op[i];
    while(l < r)
    {
        int mid = (r + l + 1) / 2;
        if(check(op, mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}