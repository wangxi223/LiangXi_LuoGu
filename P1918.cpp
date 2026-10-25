#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n;
    unordered_map<int, int> op;
    op.reserve(n * 2);
    for(int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        op[x] = i;
    }
    cin >> q;
    while(q--)
    {
        int x;
        cin >> x;
        auto i = op.find(x);
        if(i != op.end()) cout << i->second << endl;
        else cout << 0 << endl;
    }
    return 0;
}