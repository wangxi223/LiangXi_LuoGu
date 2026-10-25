#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        int ls;
        cin >> ls;
        a.push_back(ls);
    }
    sort(a.begin(), a.end());
    for(int i : a) cout << i << " ";
    return 0;
}