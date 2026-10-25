#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

long long n, m, r = 0, l = 0;

bool check(vector<long long>& op, long long mid)
{
    int x = 0, y = 0;
    for(int i = 0; i < n; i++)
    {
        if(x + op[i] <= mid) x += op[i];
        else
        {
            x = op[i];
            y++;
        }
    }
    return y < m;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<long long> op(n);
    for(int i = 0; i < n; i++)
    {
        cin >> op[i];
        l = max(l, op[i]);
        r += op[i];
    }
    while(l <= r)
    {
        long long mid = l + (r - l) / 2;
        if(check(op, mid)) r = mid - 1;
        else l = mid + 1;
    }
    cout << l << endl;
    return 0;
}