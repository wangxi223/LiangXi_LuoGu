#include <iostream>
#include <vector>
using namespace std;

long long sl = 0;

void mixl(vector<int>& a, int l, int r)
{
    if(l >= r) return;
    int mid = (l + r) / 2;
    mixl(a, l, mid);
    mixl(a, mid + 1, r);
    int i = l, k = mid + 1, p = 0;
    vector<int> tmp(r - l + 1);
    while (i <= mid && k <= r)
    {
        if(a[i] <= a[k]) tmp[p++] = a[i++];
        if(a[i] > a[k])
        {
            sl += mid - i + 1;
            tmp[p++] = a[k++];
        }
    }
    while(i <= mid) tmp[p++] = a[i++];
    while(k <= r) tmp[p++] = a[k++];
    for(int i = 0; i < tmp.size(); i++) a[i + l] = tmp[i];
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        int ls;
        cin >> ls;
        a.push_back(ls);
    }
    mixl(a, 0, a.size() - 1);
    cout << sl;
    return 0;
}