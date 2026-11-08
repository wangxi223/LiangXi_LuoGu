#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> op, tr, add, mul;

int m;

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
    return;
}

void apply1(int p, int l, int r, ll k)
{
    k %= m;
    tr[p] =  (tr[p] + (r - l + 1) * k) % m;
    add[p] = (k + add[p]) % m;
    return;
}

void apply2(int p, ll k)
{
    k %= m;
    add[p] = add[p] * k % m;
    tr[p] = tr[p] * k % m;
    mul[p] = mul[p] * k % m;
    return;
}

void pushdown(int p, int l, int r)
{
    if(l == r || (add[p] == 0 && mul[p] == 1)) return;
    int mid = (l + r) >> 1;
    if(mul[p] != 1)
    {
        apply2(p << 1, mul[p]);
        apply2(p << 1 | 1, mul[p]);
        mul[p] = 1;
    }
    if(add[p] != 0)
    {
        apply1(p << 1, l, mid, add[p]);
        apply1(p << 1 | 1, mid + 1, r, add[p]);
        add[p] = 0;
    }
    return;
}

void qukuaijia(int p, int l, int r, int pl, int pr, ll k)
{
    if(l >= pl && r <= pr)
    {
        apply1(p, l, r, k);
        return;
    }
    pushdown(p, l, r);
    int mid = (l + r) >> 1;
    if(pl <= mid) qukuaijia(p << 1, l, mid, pl, pr, k);
    if(pr > mid) qukuaijia(p << 1 | 1, mid + 1, r, pl, pr, k);
    tr[p] = (tr[p << 1] + tr[p << 1 | 1]) % m;
    return;
}

void qukuachen(int p, int l, int r, int pl, int pr, ll k)
{
    if(l >= pl && r <= pr)
    {
        apply2(p, k);
        return;
    }
    pushdown(p, l, r);
    int mid = (l + r) >> 1;
    if(pl <= mid) qukuachen(p << 1, l, mid, pl, pr, k);
    if(pr > mid) qukuachen(p << 1 | 1, mid + 1, r, pl, pr, k);
    tr[p] = (tr[p << 1] + tr[p << 1 | 1]) % m;
    return;
}

ll Find(int p, int l, int r, int pl, int pr)
{
    if(l >= pl && r <= pr) return tr[p];
    pushdown(p, l, r);
    int mid = (l + r) >> 1;
    long long ans = 0;
    if(pl <= mid) ans += Find(p << 1, l, mid, pl, pr);
    if(pr > mid) ans += Find(p << 1 | 1, mid + 1, r, pl, pr);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q >> m;
    op.assign(n + 1, 0);
    tr.assign(n * 4 + 5, 0);
    add.assign(n * 4 + 5, 0);
    mul.assign(n * 4 + 5, 1);
    for(int i = 1; i <= n; i++) cin >> op[i];
    build(1, 1, n);
    while(q--)
    {
        int pd, x, y;
        cin >> pd >> x >> y;
        if(pd == 1)
        {
            ll k;
            cin >> k;
            qukuachen(1, 1, n, x, y, k);
        }
        else if(pd == 2)
        {
            ll k;
            cin >> k;
            qukuaijia(1, 1, n, x, y, k);
        }
        else
        {
            cout << Find(1, 1, n, x, y) % m << endl;
        }
    }
}