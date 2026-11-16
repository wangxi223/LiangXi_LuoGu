#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> op(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> op[i];
    vector<int> vis(m + 1, 0);
    vis[0] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = m; j >= op[i]; j--) vis[j] += vis[j - op[i]];
    }
    cout << vis[m] << '\n';
}