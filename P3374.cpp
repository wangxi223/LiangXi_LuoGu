#include <bits/stdc++.h>
#include <vector>
using namespace std;

int n, m;

void add(int i, int v, vector<int>& op1)
{
    for(; i <= n; i += i & -i) op1[i] += v;
    return;
}

int sum(int i, vector<int>& op1)
{
    int ans = 0;
    for(; i > 0; i -= i & -i) ans += op1[i];
    return ans;
}

int rangeSum(int x, int y, vector<int>& op1)
{
    return sum(y, op1) - sum(x - 1, op1);
}

int main()
{
    cin >> n >> m;
    vector<int> op1(n + 1, 0);
    for(int i = 1; i <= n; i++)
    {
        int v = 0;
        cin >> v;
        add(i, v, op1);
    }
    for(int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if(x == 1)
        {
            add(y, z, op1);
        }
        if(x == 2)
        {
            cout << rangeSum(y, z, op1) << endl;
        }
    }
}