#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct lu {int u, v, w;};

bool paixu(lu a, lu b) {return a.w < b.w;}

int Find1(vector<int>& d, int i)
{
    if(d[i] == i) return i;
    return d[i] = Find1(d, d[i]);
}

bool Find2(int x, int y, vector<int>& d)
{
    int a = Find1(d, x);
    int b = Find1(d, y);
    if(a == b) return false;
    d[a] = b;
    return true;
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    if(k > n)
    {
        cout << "No Answer";
        return 0;
    }
    vector<lu> tu;
    for(int i = 0; i < m; i++)
    {
        int x, y, l;
        cin >> x >> y >> l;
        tu.push_back({x, y, l});
    }
    sort(tu.begin(), tu.end(), paixu);
    vector<int> d(n + 1, 0);
    vector<int> s(1, 0);
    for(int i = 1; i <= n; i++) d[i] = i;
    int j = 0;
    for(auto a : tu)
    {
        if(!Find2(a.u, a.v, d)) continue;
        s.push_back(s[s.size() - 1] + a.w);
        j++;
    }
    int f = n - k;
    if(f > j)
    {
        cout << "No Answer";
        return 0;
    }
    cout << s[f];
}