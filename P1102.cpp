#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    long long ans = 0;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    unordered_map<int, int> op;
    op.reserve(a.size() * 2);
    for(int i : a) op[i]++;
    for(int i : a)
    {
        auto x = op.find(i + m);
        if(x != op.end()) ans += x->second;
    }
    cout << ans << endl;
}