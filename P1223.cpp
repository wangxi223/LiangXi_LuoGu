#include <algorithm>
#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

bool bj(pair<int, int>& op1, pair<int, int>& op2)
{
    if(op1.second != op2.second) return op1.second < op2.second;
    else return op1.first < op2.first;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> op;
    for(int i = 1; i <= n; i++)
    {
        int j;
        cin >> j;
        op.push_back({i, j});
    }
    sort(op.begin(), op.end(), bj);
    double j = 0, k = 0;
    for(auto [x, y] : op)
    {
        cout << x << " ";
        j += k;
        k += y;
    }
    cout << endl;
    printf("%.2f", j / op.size());
    return 0;
}