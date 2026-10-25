#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

const int INF = 0x3f3f3f3f;

void Dijkstra(const vector<vector<pair<int, int>>>& tu, int s)
{
    vector<int> dis(tu.size(), INF);
    dis[s] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> op;
    op.push({dis[s], s});
    while(!op.empty())
    {
        auto[du, u] = op.top();
        op.pop();
        if(du > dis[u]) continue;
        for(auto [v, w] : tu[u])
        {
            if(w + du < dis[v])
            {
                dis[v] = w + du;
                op.push({dis[v], v});
            }
        }
    }
    for(int i : dis)
    {
        if(i == INF) continue;
        else cout << i << " ";
    }
}

int main()
{
    int n ,m, s;
    cin >> n >> m >> s;
    vector<vector<pair<int, int>>> tu (n + 1);
    for(int i = 0; i < m; i++)
    {
        int iv, iu, iw;
        cin >> iv >> iu >> iw;
        tu[iv].push_back({iu, iw});
    }
    Dijkstra(tu, s);
    return 0;
}