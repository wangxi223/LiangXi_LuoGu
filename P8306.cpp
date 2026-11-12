#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<char, int>>> ch;
vector<int> cnt;

void reset() { ch.clear(); ch.push_back({}); cnt.assign(1, 0); }

void insert(const string& op)
{
    int u = 0;
    for(int i : op)
    {
        int v= -1;
        for(auto& c : ch[u]) if(c.first == i) {v = c.second; break;}
        if(v < 0)
        {
            v = ch.size();
            ch.push_back({});
            cnt.push_back(0);
            ch[u].push_back({i, v});
        }
        u = v;
        cnt[u]++;
    }
}

int query(const string& op)
{
    int u = 0;
    for(char i : op)
    {
        int v = -1;
        for(auto& c : ch[u]) if(c.first == i) {v = c.second; break;}
        if(v < 0) return 0;
        u = v;
    }
    return cnt[u];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
    {
        reset();
        int n, m;
        cin >> n >> m;
        while(n--)
        {
            string zf;
            cin >> zf;
            insert(zf);
        }
        while(m--)
        {
            string op;
            cin >> op;
            cout << query(op) << '\n';
        }
    }
}