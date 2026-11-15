#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<char, int>>> ch;
vector<int> cnt, fail, vis;

void reset() {ch.clear(); ch.push_back({}); cnt.assign(1, 0);}

void insert(const string& op)
{
    int u = 0;
    for(char c : op)
    {
        int v = -1;
        for(auto& k : ch[u]) if(k.first == c) {v = k.second; break;}
        if(v < 0)
        {
            v = ch.size();
            ch.push_back({});
            cnt.push_back(0);
            ch[u].push_back({c, v});
        }
        u = v;
    }
    cnt[u]++;
}

int Find(int u, char c)
{
    for(auto& k : ch[u]) if(k.first == c) return k.second;
    return -1;
}

void buildFail()
{
    fail.assign(ch.size(), 0);
    queue<int> op;
    for(auto k : ch[0])
    {
        fail[k.second] = 0;
        op.push(k.second);
    }
    while(!op.empty())
    {
        int u = op.front();
        op.pop();
        for(auto e : ch[u])
        {
            int f = fail[u];
            while(f && Find(f, e.first) < 0) f = fail[f];
            int nx = Find(f, e.first);
            fail[e.second] = (nx < 0) ? 0 : nx;
            op.push(e.second); 
        }
    }
}

int query(const string& op)
{
    vis.assign(ch.size(), 0);
    int ans = 0, u = 0;
    for(char c : op)
    {
        int v;
        while((v = Find(u, c)) < 0 && u) u = fail[u];
        u = (v < 0 ? 0 : v);
        for(int  j = u; j; j = fail[j])
        {
            if(vis[j]) break;
            vis[j] = 1;
            ans += cnt[j];
        }
    }
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    reset();
    while(n--)
    {
        string k;
        cin >> k;
        insert(k);
    }
    buildFail();
    string t;
    cin >> t;
    cout << query(t) << '\n';
}