#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, n;
    cin >> v >> n;
    vector<int> w(n + 1), f(v + 1, 0);
    for(int i = 1; i <= n; i++) cin >> w[i];
    for(int i = 1; i <= n; i++)
    for(int j = v; j >= w[i]; j--)
    {
        f[j] = max(f[j], f[j - w[i]] + w[i]);
    }
    cout << v - f[v] << endl;
    return 0;
}