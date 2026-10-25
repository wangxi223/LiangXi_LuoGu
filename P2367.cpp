#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin .tie(nullptr);
    int n, p;
    cin >> n >> p;
    vector<int> op(n + 1, 0), op1(n + 3, 0);
    for(int i = 1; i <= n; i++) cin >> op[i];
    for(int i = 1; i <= n; i++) op1[i] = op[i] - op[i - 1];
    for(int i = 0; i < p; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        op1[x] += z;
        op1[y + 1] -= z;
    }
    for(int i = 1; i <= n; i++) op[i] = op1[i] + op[i - 1];
    sort(op.begin() + 1, op.end());
    cout << op[1] << endl;
    return 0;
}