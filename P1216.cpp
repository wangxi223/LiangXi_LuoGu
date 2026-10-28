#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ks;
    cin >> n;
    vector<vector<int>> op(n);
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            int sz;
            cin >> sz;
            op[i].push_back(sz);
        }
    }
    for(int i = op.size() - 2; i >= 0; i--)
    {
        for(int j = 0; j < op[i].size(); j++)
        {
            op[i][j] += max(op[i + 1][j], op[i + 1][j + 1]);
        }
    }
    cout << op[0][0] << endl;
    return 0;
}