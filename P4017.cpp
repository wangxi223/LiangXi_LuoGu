#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int n, m, A, B ,MOD = 80112002;
    cin >> n >> m;
    vector<vector<int>> swl(n + 1);
    vector<int> rd(n + 1, 0);
    vector<int> jx(n + 1, 0);
    for(int i = 0; i < m; i++)
    {
        cin >> A >> B;
        swl[A].push_back(B);
        rd[B]++;
    }
    queue<int> op;
    for(int i = 1; i <= n; i++) if(rd[i] == 0)
    {
        op.push(i);
        jx[i] = 1;
    }
    while(!op.empty())
    {
        int u = op.front();
        op.pop();
        for(int v : swl[u])
        {
            jx[v] = (jx[u] + jx[v]) % MOD;
            if(--rd[v] == 0) op.push(v);
        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(swl[i].empty()) ans = (ans + jx[i]) % MOD;
    }
    cout << ans;
    return 0;
}