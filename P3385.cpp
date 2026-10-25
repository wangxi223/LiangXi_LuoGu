#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

bool SPFA(int s, vector<long long>& dis, vector<vector<pair<int, long long>>>& tu)
{
    vector<int> ent(dis.size(), 0);
    vector<bool> inq(dis.size(), false);
    queue<int> op;
    dis[s] = 0;
    op.push(s);
    inq[s] = true;
    while(!op.empty())
    {
        int u = op.front();
        op.pop();
        inq[u] = false;
        for(auto [v, w] : tu[u])
        {
            if(dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                ent[v] = ent[u] + 1;
                if(ent[v] >= dis.size() - 1) return false;
                if(!inq[v])
                {
                    op.push(v);
                    inq[v] = true;
                }
            }
        }
    }
    return true;
}

int main()
{
    int T, n, m, u, v;
    long long w;
    cin >> T;
    for(int i = 0; i < T; i++)
    {
        cin >> n >> m;
        vector<vector<pair<int, long long>>> tu(n + 1);
        vector<long long> dis(n + 1, INF);
        for(int j = 0; j < m; j++)
        {
            cin >> u >> v >> w;
            if(w < 0) tu[u].push_back({v, w});
            else
            {
                tu[u].push_back({v, w});
                tu[v].push_back({u, w});
            }
        }
        if(SPFA(1, dis, tu)) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}