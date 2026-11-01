#include <bits/stdc++.h>
using namespace std;

struct lu {int u, v, w;};

bool paixu(lu a, lu b) {return a.w < b.w;}

int Find(vector<int>& op, int i)
{
    if(op[i] == i) return i;
    return op[i] = Find(op, op[i]);
}

int main()
{
    int n ,m, s, t;
    cin >> n >> m >> s >> t;
    vector<lu> tu;
    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        tu.push_back({u, v, w});
    }
   sort(tu.begin(), tu.end(), paixu);
   vector<int> op(n + 1, 0);
   for(int i = 1; i <= n; i++) op[i] = i;
   int ans = 0;
   for(auto [u, v, w] : tu)
    {
        int x = Find(op, u);
        int y = Find(op, v);
        if(x != y)
        {
            op[x] = y;
            ans = w;
        }
        if(Find(op, s) == Find(op, t)) break;
    }
   cout << ans;
}