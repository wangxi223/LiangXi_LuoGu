#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> op(n + 1, 0), f(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> op[i];
    for(int i = 1; i <= n; i++) f[i] = max(op[i], f[i - 1] + op[i]);
    long long ans = f[1];
    for(int i = 1; i <= n; i++) ans = max(ans, f[i]);
    cout << ans << endl;
}