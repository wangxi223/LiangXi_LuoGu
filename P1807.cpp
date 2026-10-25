#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const long long NEG = -1e18;                  // 表示"还没法到达"

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> tu(n + 1);  // ★① tu[u] = {终点, 边权}
    vector<int> rd(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        tu[u].push_back({v, w});              // ★② 权值跟着边走
        rd[v]++;
    }

    vector<long long> d(n + 1, NEG);          // ★③ 最长路数组
    d[1] = 0;

    queue<int> op;
    for (int i = 1; i <= n; i++)
        if (rd[i] == 0) op.push(i);           // ★④ 所有入度 0 的点，不是只有 1

    while (!op.empty())
    {
        int u = op.front();
        op.pop();

        if (d[u] != NEG)                      // 到不了的点没法往外转移
            for (auto [v, w] : tu[u])
                d[v] = max(d[v], d[u] + w);   // ★③ 转移方程

        for (auto [v, w] : tu[u])
            if (--rd[v] == 0) op.push(v);
    }

    cout << (d[n] == NEG ? -1 : d[n]) << endl;  // ★ 靠 d[n] 判断可达
    return 0;
}