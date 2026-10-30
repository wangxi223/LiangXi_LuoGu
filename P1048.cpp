#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, m;
    cin >> t >> m;
    vector<int> w(m + 1), v(m + 1), f(t + 1, 0);
    for(int i = 1; i <= m; i++) cin >> w[i] >> v[i];
    for(int i = 1; i <= m; i++)
    for(int j = t; j >= w[i]; j--)
    {
        f[j] = max(f[j], f[j - w[i]] + v[i]);
    }
    cout << f[t] << endl;
    return 0;
}