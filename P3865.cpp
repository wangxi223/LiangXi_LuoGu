#include <bits/stdc++.h>
using namespace std;

inline int read()
{
	int x=0,f=1;char ch=getchar();
	while (ch<'0'||ch>'9'){if (ch=='-') f=-1;ch=getchar();}
	while (ch>='0'&&ch<='9'){x=x*10+ch-48;ch=getchar();}
	return x*f;
}

int main()
{
    int n = read(), m = read(), lg = 0;
    while(1 << (lg + 1) <= n) lg++;
    vector<vector<int>> st(n + 1, vector<int>(lg + 1, 0));
    for(int i = 1; i <= n; i++) st[i][0] = read();
    for(int len = 1; len <= lg; len++)
    {
        for(int i = 1; i + (1 << len) - 1 <= n; i++) st[i][len] = max(st[i][len - 1], st[i + (1 << (len - 1))][len - 1]);
    }
    vector<int> log(n + 1, 0);
    for(int i = 2; i <= n; i++)
    {
        log[i] = log[i >> 1] + 1;
    }
    while(m--)
    {
        int l = read(), r = read();
        int k = log[r - l + 1];
        cout << max(st[l][k], st[r - (1 << k) + 1][k]) << '\n';
    }
}