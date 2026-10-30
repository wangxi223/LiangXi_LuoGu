#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int t, m;
    cin >> t >> m;
    vector<int> w(m + 1), v(m + 1);
    vector<long long>  f(t + 1, 0);
    for(int i = 1; i <= m; i++) cin >> w[i] >> v[i];
    for(int i = 1; i <= m; i++)
    for(int j = w[i]; j <= t; j++)
    {
        f[j] = max(f[j], f[j - w[i]] + v[i]);
    }
    cout << f[t] << endl;
    return 0;
}