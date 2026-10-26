#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string n, m;
    cin >> n >> m;
    vector<int> pi(m.size(), 0);
    for(int i = 1; i < m.size(); i++)
    {
        int j = pi[i - 1];
        while(j > 0 && m[j] != m[i]) j = pi[j - 1];
        if(m[j] == m[i]) j++;
        pi[i] = j;
    }
    int j = 0;
    for(int i = 0; i < n.size(); i++)
    {
        while(j > 0 && n[i] != m[j]) j = pi[j - 1];
        if(n[i] == m[j]) j++;
        if(j == m.size())
        {
            cout << i - m.size() + 2 << endl;
            j = pi[j - 1];
        }
    }
    for(int i : pi) cout << i << " ";
    return 0;
}