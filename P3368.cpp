#include <bits/stdc++.h>
#include <vector>
using namespace std;

int n, m;

void add(int i, int v, vector<int>& op)
{
    for(; i <= n; i += i & -i)
    {
        op[i] += v;
    }
}

int sum(int i, vector<int>& op)
{
    int ans = 0;
    for(; i > 0; i -= i & -i)
    {
        ans += op[i];
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    vector<int> op(n + 1, 0), op1(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> op1[i];
    for(int i = 1; i <= n; i++)
    {
        add(i, op1[i] - op1[i - 1], op);
    }
    for(int i = 0; i < m; i++)
    {
        int cz;
        cin >> cz;
        if(cz == 1)
        {
            int x, y, z;
            cin >> x >> y >> z;
            add(x, z, op);
            add(y + 1, -z, op);
        }
        if(cz == 2)
        {
            int x;
            cin >> x;
            cout << sum(x, op) << endl;
        }
    }
}