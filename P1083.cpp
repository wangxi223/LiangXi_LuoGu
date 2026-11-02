#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct sj {int d, s, t;};

int n;

bool check(int mid, vector<sj>& zujie, vector<int>& tian)
{
    vector<long long> cf(n + 2, 0);
    for(int i = 0; i < mid; i++)
    {
        cf[zujie[i].s] += zujie[i].d;
        cf[zujie[i].t + 1] -= zujie[i].d;
    }
    long long ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += cf[i];
        if(ans > tian[i]) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> n >> m;
    vector<int> tian(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> tian[i];
    vector<sj> zujie;
    for(int i = 0; i < m; i++)
    {
        int d, s, t;
        cin >> d >> s >> t;
        zujie.push_back({d, s, t});
    }
    if(check(m, zujie, tian))
    {
        cout << 0;
        return 0;
    }
    int l = 1, r = m;
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(check(mid, zujie, tian)) l = mid + 1;
        else r = mid;
    }
    cout << -1 << endl << l;
}