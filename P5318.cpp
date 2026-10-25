#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void DFS(vector<int> n[], vector<bool>& vis, int v)
{
    for(int k = 0; k < n[v].size(); k++)
    {
        if(vis[n[v][k]] != true)
        {
            int i = n[v][k];
            vis[i] = true;
            cout << i << " ";
            DFS(n, vis, i);
        }
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y;
    cin >> x >> y;
    vector<int> a[x + 1];
    for(int i = 0; i < y; i++)
    {
        int o, p;
        cin >> o >> p;
        a[o].push_back(p);
    }
    for(int i = 1; i <= x; i++) sort(a[i].begin(), a[i].end());
    vector<bool> vis(x + 1, false);
    cout << 1 << " ";
    vis[1] = true;
    DFS(a, vis, 1);
    cout << "\n";
    vis.assign(x + 1, false);
    queue<int> t;
    t.push(1);
    vis[1] = true;
    while(!t.empty())
    {
        int i = t.front();
        for(int k = 0; k < a[i].size(); k++)
        {
           int u = a[i][k];
            if(!vis[u])
            {
                t.push(u);
                vis[u] = true;
            }
        }
        cout << i << " ";
        t.pop();
    }
    return 0;
}