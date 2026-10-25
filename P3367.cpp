#include <iostream>
#include <vector>
using namespace std;

int find(vector<int>& n, int x)
{
    if(n[x] <= -1) return x;
    else return n[x] = find(n, n[x]);
}
    
void find2(vector<int>& n, int x, int y)
{
    int a = find(n, x);
    int b = find(n, y);
    if(a == b) cout << "Y" << endl;
    else cout << "N" << endl;
    return;
}

void cr(vector<int>& n, int x, int y)
{
    int a = find(n, x);
    int b = find(n, y);
    if(a == b) return;
    if(n[a] > n[b]) swap(a, b);   // 让 a 是更大的集合（n[a] 更负）
    n[a] += n[b];                 // 负数相加 = 大小相加
    n[b] = a;                     // b 的父节点设为 a
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> bi(n + 1, -1);
    for(int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> z >> x >> y;
        if(z == 1) cr(bi, x, y);
        if(z == 2) find2(bi, x, y);
    }
    return 0;
}