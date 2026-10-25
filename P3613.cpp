#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

const long long BASE = 1000005;

int main()
{
    int n, p;
    cin >> n >> p;
    unordered_map<long long, long long> op;
    for(int i = 0; i < p; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        if(x == 1)
        {
            int k;
            cin >> k;
            if(k == 0) op.erase(y * BASE + z);
            else op[y * BASE + z] = k;
        }
        else cout << op[y * BASE + z] << endl;
    }
    return 0;
}