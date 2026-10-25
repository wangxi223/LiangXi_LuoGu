#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

bool bj(pair<string, int> a, pair<string, int> b)
{
    if(a.first.length() != b.first.length()) return a.first.length() > b.first.length();
    else if(a.first.length() == b.first.length()) return a.first > b.first;
    else return a.second < b.second;
}

int main()
{
    int rx;
    cin >> rx;
    vector<pair<string, int>> a;
    for (int i = 1; i <= rx; i++)
    {
        string b;
        cin >> b;
        a.push_back({b, i});
    }
    sort(a.begin(), a.end(), bj);
    cout << a[0].second << endl << a[0].first;
    return 0;
}