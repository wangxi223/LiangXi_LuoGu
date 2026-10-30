#include <bits/stdc++.h>
#include <set>
#include <vector>
using namespace std;

int main()
{
    vector<int> op(7, 0);
    for(int i = 1; i <= 6; i++) cin >> op[i];
    vector<int> w(1, 0);
    if(op[1] != 0) for(int i = 0; i < op[1]; i++) w.push_back(1);
    if(op[2] != 0) for(int i = 0; i < op[2]; i++) w.push_back(2);
    if(op[3] != 0) for(int i = 0; i < op[3]; i++) w.push_back(3);
    if(op[4] != 0) for(int i = 0; i < op[4]; i++) w.push_back(5);
    if(op[5] != 0) for(int i = 0; i < op[5]; i++) w.push_back(10);
    if(op[6] != 0) for(int i = 0; i < op[6]; i++) w.push_back(20);
    vector<int> f(1001, 0);
    for(int i = 1; i < w.size(); i++)
    for(int j = 1000; j >= w[i]; j--)
    {
        f[j] = max(f[j], f[j - w[i]] + w[i]);
    }
    set<int> ans;
    for(int i : f) if(i != 0) ans.insert(i);
    cout << "Total=" << ans.size() << endl;
    return 0;
}