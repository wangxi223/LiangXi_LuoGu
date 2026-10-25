#include <iostream>
#include <utility>
#include <vector>
using namespace std;

struct kongdong
{
    int next;
    long long x;
    long long y;
    long long z;
};

int Find(vector<kongdong>& n, int a)
{
    if(n[a].next <= -1) return a;
    else return n[a].next = Find(n, n[a].next);
}

bool Find2(vector<kongdong>& n, int a, int b)
{
    if(a == b) return true;
    int x = Find(n, a);
    int y = Find(n, b);
    if(x == y) return true;
    else return false;
}

bool js(vector<kongdong>& n, int a, int b, int r)
{
    if((n[a].x - n[b].x) * (n[a].x - n[b].x) + (n[a].y - n[b].y) * (n[a].y - n[b].y) + (n[a].z - n[b].z) * (n[a].z - n[b].z) <= (2LL * r) * (2LL * r)) return false;
    else return true;
}

void jr(vector<kongdong>& n, int a, int b, int r)
{
    int x = Find(n, a);
    int y = Find(n, b);
    if(x == y || js(n, a, b, r)) return;
    else
    {
        if(n[x].next > n[y].next) swap(x, y);
        n[x].next += n[y].next;
        n[y].next = x;
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        bool yes = true;
        int n, h;
        long long r;
        cin  >> n >> h >> r;
        vector<kongdong> op(n + 1);
        vector<bool> shang(n + 1, false);
        vector<bool> xia(n + 1, false);
        for(int j = 1; j <= n; j++)
        {
            long long x, y, z;
            cin >> x >> y >> z;
            op[j] = {-1, x, y, z};
            if(z + r >= h) shang[j] = true;
            if(z - r <= 0) xia[j] = true;
        }
        for(int j = 1; j <= n - 1; j++)
        {
            for(int k = j + 1; k <= n; k++) jr(op, j, k, r);
        }
        for(int j = 1; j <= n; j++)
        {
            if(shang[j]) for(int k = 1; k <= n; k++)
            {
                if(xia[k]) if(Find2(op, j, k))
                {
                    if(yes) cout << "Yes" << endl;
                    yes = false;
                    break;
                }
            }
        }
        if(yes) cout << "No" << endl;
    }
    return 0;
}