#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> op(n + 1, 0);
    for(int i = 1; i <= n; i++) cin >> op[i];
    sort(op.begin() + 1, op.end());
    long long m = 0, j = 0, p = 0;
    bool k = false;
    for (int i=1;i<=n;i++)
    {
        j = n - j + k;
        k = !k;
        m += (op[j] - p) * (op[j] - p);
        p = op[j];
    }
    cout << m << endl;
    return 0;
}