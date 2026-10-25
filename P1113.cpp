#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;

    vector<vector<int>> edges(n + 1);
    vector<int> in_degree(n + 1, 0);
    vector<int> len(n + 1, 0);
    vector<int> dp(n + 1, 0);

    
    for(int i = 1; i <= n; i++)
    {
        int id, l, elpt;
        cin >> id >> l;
        dp[id] = l;
        len[id] = l;

        while(cin >> elpt && elpt != 0)
        {
            edges[elpt].push_back(id);
            in_degree[id]++;
        }
    }

    queue<int> op;
    for(int i = 1; i <= n; i++) if(in_degree[i] == 0) op.push(i);

    int ans = 0;

    while(!op.empty())
    {
        int u = op.front();
        op.pop();

        ans = max(ans, dp[u]);

        for(int v : edges[u])
        {
            dp[v] = max(dp[v], dp[u] + len[v]);
            if(--in_degree[v] == 0) op.push(v);
        }
    }
    cout << ans << endl;

    return 0;
}