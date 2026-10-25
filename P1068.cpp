#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool bj(pair<int,int> a, pair<int,int> b)
{
    if(a.second != b.second) return a.second > b.second;
    else return a.first < b.first;
}

int main()
{
    int n, m;
    cin >> n >> m;
    m = m * 1.5;
    vector<pair<int,int>> a;
    for(int i = 0; i < n; i++)
    {
        int id, fx;
        cin >> id >> fx;
        a.push_back({id,fx}); 
    }
    sort(a.begin(), a.end(), bj);
    int fsx = a[m - 1].second;
    int rx = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i].second >= fsx) rx++;
        else break;
    }
    cout << fsx << " " << rx << endl;
    int i = 0;
    while (fsx <= a[i].second)
    {
        cout << a[i].first << " " << a[i].second << endl;
        i++;
    }
    return 0;
}