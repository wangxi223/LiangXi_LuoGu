#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void paixu(vector<int>& n, int l, int r)
{
    if(l >= r) return;
    int i = l, k = r, mid = (l + r) / 2;
    int p = n[mid];
    while(i <= k)
    {
        while(n[i] < p) i++;
        while(n[k] > p) k--;
        if(i <= k)
        {
            swap(n[i], n[k]);
            i++;
            k--;
        }
    }
    if(l < k) paixu(n, l, k);
    if(i < r) paixu(n, i, r);
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y;
    cin >> x >> y;
    vector<int> n(x);
    for(int i = 0; i < x; i++) cin >> n[i];
    paixu(n, 0, x - 1);
    cout << n[y] << endl;
    return 0;
}