#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u); // 无向图，双向加边
    }

    vector<int> color(n + 1, 0); // 0 未染色，1/2 两种颜色
    int ans = 0;

    for (int s = 1; s <= n; s++)
    {
        if (color[s]) continue; // 已属于之前的连通块

        queue<int> q;
        q.push(s);
        color[s] = 1;

        int cnt[3] = {0, 0, 0};
        cnt[1] = 1; // 初始点颜色计数

        bool ok = true;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : g[u])
            {
                if (!color[v])
                {
                    color[v] = 3 - color[u]; // 染相反颜色
                    cnt[color[v]]++;
                    q.push(v);
                }
                else if (color[v] == color[u])
                {
                    ok = false; // 相邻同色 → 不是二分图
                    break;
                }
            }
            if (!ok) break;
        }

        if (!ok)
        {
            cout << "Impossible" << endl;
            return 0;
        }

        ans += min(cnt[1], cnt[2]); // 当前连通块取较少颜色
    }

    cout << ans << endl;
    return 0;
}