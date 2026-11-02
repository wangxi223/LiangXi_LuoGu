#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

struct fenzi {int w, u, v, f;};

int main()
{
    int n;
    cin >> n;
    vector<fenzi> shu(n + 1, {0, 0, 0, 0});
    for(int i = 1; i <= n; i++)
    {
        int w, u, v;
        cin >> w >> u >> v;
        shu[i] = {w, u, v, shu[i].f};
        shu[u].f = i;
        shu[v].f = i;
    }
    int ans = 1e9;
    for(int i = 1; i <= n; i++)
    {
        vector<bool> vis(n + 1, true);
        queue<pair<int, int>> op;
        op.push({i, 0});
        vis[i] = false;
        int ls = 0;
        while(!op.empty())
        {
            auto [t, js] = op.front();
            op.pop();
            fenzi k = shu[t];
            if(k.u != 0 && vis[k.u]) op.push({k.u, js + 1}), vis[k.u] = false;
            if(k.v != 0 && vis[k.v]) op.push({k.v, js + 1}), vis[k.v] = false;
            if(k.f != 0 && vis[k.f]) op.push({k.f, js + 1}), vis[k.f] = false;
            ls += js * k.w;
        }
        ans = min(ans, ls);
    }
    cout << ans;
}