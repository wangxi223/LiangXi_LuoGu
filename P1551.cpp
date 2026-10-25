#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int Find(vector<int>& n, int a)
{
    if(n[a] <= -1) return a;
    else return n[a] = Find(n, n[a]);
}

void Find2(vector<int>& n, int a, int b)
{
    int x = Find(n, a);
    int y = Find(n, b);
    if(x == y) cout << "Yes" << endl;
    else cout << "No" << endl;
    return;
}

void jr(vector<int>& n, int a, int b)
{
    int x = Find(n, a);
    int y = Find(n, b);
    if(x == y) return;
    if(x > y) swap(x, y);
    n[x] += n[y];
    n[y] = x;
    return;
}

int main()
{
    int n, m, p;
    cin >> n >> m >> p;
    vector<int> op(n + 1, -1);
    for(int i = 0; i < m; i++)
    {
        int mi, mj;
        cin >> mi >> mj;
        jr(op, mi, mj);
    }
    for(int i = 0; i < p; i++)
    {
        int pi, pj;
        cin >> pi >> pj;
        Find2(op, pi, pj);
    }
    return 0;
}