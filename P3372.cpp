#include <bits/stdc++.h>
using namespace std;

#define ll long long
 
vector<ll> tr, tag, op;

void build(int p, int l, int r)
{
    if(l == r)
    {
        tr[p] = op[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    tr[p] = tr[p << 1] + tr[p << 1 | 1];
}

void apply(int p, int l, int r, ll k)
{
    tr[p] += (r - l + 1) * k;
    tag[p] += k;
    return;
}

void pushdown(int p, int l, int r)
{
    if(l == r) return;
    if(tag[p] == 0) return;
    int mid = (l + r) >> 1;
    apply(p << 1, l, mid, tag[p]);
    apply(p << 1 | 1, mid + 1, r, tag[p]);
    tag[p] = 0;
    return;
}

ll Find(int p, int l, int r, int x, int y)
{
    if(x <= l && y >= r) return tr[p];
    pushdown(p, l, r);
    int mid = ( l + r) >> 1;
    ll ans = 0;
    if(x <= mid) ans += Find(p << 1, l, mid, x, y);
    if(y > mid) ans += Find(p << 1 | 1, mid + 1, r, x, y);
    return ans;
}

void qukuaijia(int p, int l, int r, int x, int y, ll k)
{
    if(x <= l && y >= r)
    {
        apply(p, l, r, k);
        return;
    }
    pushdown(p, l, r);
    int mid = (l + r) >> 1;
    if(x <= mid) qukuaijia(p << 1, l, mid, x, y, k);
    if(y > mid) qukuaijia(p << 1| 1, mid + 1, r, x, y, k);
    tr[p] = tr[p << 1] + tr[p << 1 | 1];
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    op.assign(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> op[i];
    tr.assign(4 * n + 5, 0);
    tag.assign(4 * n + 5, 0);
    build(1, 1, n);
    while(m--)
    {
        int t, x, y;
        cin >> t >> x >> y;
        if(t == 1)
        {
            ll k;
            cin >> k;
            qukuaijia(1, 1, n, x, y, k);
        }
        else
        {
            cout << Find(1, 1, n, x, y) << endl;
        }
    }
}