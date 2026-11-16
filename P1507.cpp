#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct wuping {int h, t, k;};

int main()
{
    int H, T, n;
    cin >> H >> T >> n;
    vector<wuping> op(n + 1, {0, 0, 0});
    for(int i = 1; i <= n; i++) cin >> op[i].h >> op[i].t >> op[i].k;
    vector<vector<int>> f(H + 1, vector<int>(T + 1, 0));
    for(int i = 1; i <= n; i++)
    {
        for(int j = H; j >= op[i].h; j--)
        {
            for(int k = T; k >= op[i].t; k--) f[j][k] = max(f[j][k], f[j - op[i].h][k - op[i].t] + op[i].k);
        }
    }
    cout << f[H][T] << '\n';
}