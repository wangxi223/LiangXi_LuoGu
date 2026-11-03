#include <bits/stdc++.h>
using namespace std;

int b = 0;

bool check(int mid, int n, vector<int>& tu_fe, vector<vector<pair<int, int>>>& tu)
{
    if(tu_fe[1] > mid) return false;
    vector<long long> dis(n + 1, 1e18);
    vector<bool> vis(n + 1, false);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> op;
    op.push({0, 1});
    dis[1] = 0;
    while(!op.empty())
    {
        auto [d, u] = op.top();
        op.pop();
        if(vis[u]) continue;
        vis[u] = true;
        if(d > dis[u]) continue;
        for(auto [v, w] : tu[u])
        {
            if(tu_fe[v] > mid) continue;
            if(dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                op.push({dis[v], v});
            }
        }
    }
    return dis[n] <= b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, MAX = 0;
    cin >> n >> m >> b;
    vector<int> tu_fe(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        cin >> tu_fe[i];
        MAX = max(MAX, tu_fe[i]);
    }
    vector<vector<pair<int, int>>> tu(n + 1);
    for(int i = 0; i < m; i++)
    {
        int u, v, t;
        cin >> u >> v >> t;
        tu[u].push_back({v, t});
        tu[v].push_back({u, t});
    }
    if(!check(MAX, n, tu_fe, tu))
    {
        cout << "AFK";
        return 0;
    }
    int l = 0, r = MAX;
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(check(mid, n, tu_fe, tu)) r = mid;
        else l = mid + 1;
    }
    cout << l;
}