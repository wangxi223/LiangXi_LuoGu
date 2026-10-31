#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, m;
    cin >> n >> m;
    vector<long long> p(m + 1, 0), piao1(n, 0), piaoc(n, 0), piao3(n, 0), d(n + 2, 0);
    vector<long long> f(n, 0);
    vector<pair<long long, long long>> piao2(n, {0, 0});
    for(int i = 1; i <= m; i++) cin >> p[i];
    for(int i = 1; i < n; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;
        piao1[i] = a;
        piao2[i] = {b, c};
    }
    for(int i = 1; i < m; i++)
    {
        long long l = min(p[i], p[i + 1]);
        long long r = max(p[i], p[i + 1]);
        d[l]++;
        d[r]--;
    }
    for(int i = 1; i < n; i++) piao3[i] = piao3[i - 1] + d[i];
    for(int i = 1; i < n; i++) f[i] = min(piao3[i] * piao1[i], piao2[i].second + piao2[i].first * piao3[i]);
    long long ans = 0;
    for(long long i : f) ans += i;
    cout << ans << endl;
}