#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n, b;
    cin >> n >> b;
    vector<int> h;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        h.push_back(a);
    }
    sort(h.begin(), h.end(), greater<int>());
    int dd = 0;
    for(int i = 0; i < n; i++)
    {
        dd += h[i];
        if(dd >= b)
        {
            cout << i + 1 << endl;
            break;
        }
    }
    return 0;
}