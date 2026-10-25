#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> tu(n + 1);
    vector<int> rd(n + 1, 0);
    char u, fugao, v;
    for(int i = 1; i <= m; i++)
    {
        cin >> u >> fugao >> v;
        if(fugao == '<')
        {
            tu[u - 64].push_back({v - 64, 1});
            rd[v - 64]++;
        }
        if(fugao == '>')
        {
            tu[v - 64].push_back({u - 64, 1});
            rd[u - 64]++;
        }
        vector<char> px;
        vector<int> rd1 = rd;
        queue<int> op;
        for(int k = 1; k <= n; k++) if(rd[k] == 0) op.push(k);
        bool biaoji = true;
        int js = 0;
        while(!op.empty())
        {
            if(op.size() > 1) biaoji = false;
            int ls = op.front();
            op.pop();
            px.push_back(ls + 64);
            js++;
            for(auto [j, ll] : tu[ls])
            {
                if(--rd1[j] == 0) op.push(j);
            }
        }
        for(int k : rd1) if(k != 0)
        {
            cout << "Inconsistency found after " << i << " relations." << endl;
            return 0;
        }
        if(js == n && biaoji)
        {
            cout << "Sorted sequence determined after "<< i << " relations: ";
            for(char k : px) cout << k;
            cout << "." << endl;
            return 0;
        }
    }
    cout << "Sorted sequence cannot be determined." <<endl;
    return 0;
}