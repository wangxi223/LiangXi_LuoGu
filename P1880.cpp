#include <bits/stdc++.h>
using namespace std;

const int TFS = 1e9;

int main()
{
    int n;
    cin >> n;
    vector<int> x(2 * n + 1, 0), s(2 * n + 1, 0);
    vector<vector<int>> op(2 * n + 1, vector<int>(2 * n + 1, TFS)), op1(2 * n + 1, vector<int>(2 * n + 1, 0));
    for(int i = 0; i < op.size(); i++) op[i][i] = 0;
    for(int i = 1; i <= n; i++) cin >> x[i];
    for(int i = 1; i <= n; i++) x[i + n] = x[i];
    for(int i = 1; i <= 2 * n; i++) s[i] = s[i - 1] + x[i];
    for(int len = 2; len <= n; len++)
    for(int l = 1; l + len - 1 <= 2 * n; l++)
    {
        int r = l + len - 1;
        for(int k = l; k < r; k++) op[l][r] = min(op[l][r], op[l][k] + op[k + 1][r]);
        op[l][r] += s[r] - s[l - 1];
    }
    int ans = TFS;
    for(int i = 1; i <= n; i++) ans = min(ans, op[i][i + n - 1]);
    cout << ans << endl;
    for(int len = 2; len <= n; len++)
    for(int l = 1; l + len - 1 <= 2 * n; l++)
    {
        int r = l + len - 1;
        for(int k = l; k < r; k++) op1[l][r] = max(op1[l][r], op1[l][k] + op1[k + 1][r]);
        op1[l][r] += s[r] - s[l - 1]; 
    }
    ans = 0;
    for(int i = 1; i <= n; i++) ans = max(ans, op1[i][i + n -1]);
    cout << ans;
}