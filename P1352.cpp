#include <bits/stdc++.h>
#include <vector>
using namespace std;

int dfs(int u, vector<int>& op1, vector<vector<int>>& op2, vector<vector<int>>& f)
{
    f[u][1] = op1[u];
    for(int v : op2[u])
    {
        dfs(v, op1, op2, f);
        f[u][0] += max(f[v][0], f[v][1]);
        f[u][1] += f[v][0];
    }
    return max(f[u][0], f[u][1]);
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> f(n + 1, vector<int>(2, 0));
    vector<int> op1(n + 1, 0);
    vector<vector<int>> op2(n + 1);
    vector<bool> pd(n + 1, true);
    for(int i = 1; i <= n; i++) cin >> op1[i];
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> v >> u;
        op2[u].push_back(v);
        pd[v] = false;
    }
    int a;
    for(int i = 1; i <= n; i++) if(pd[i]) a = i;
    int ans = dfs(a, op1, op2, f);
    cout << ans << endl;
}