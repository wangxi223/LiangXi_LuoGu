#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> a;
int sl, k, n;

bool yz(int a)
{
    if(a < 2) return false;
    for(int i = 2; i*i <= a; i++)
    {
        if(a%i == 0) return false;
    }
    return true;
}

void jf(int b, int c, int d)
{
    if(c == k)
    {
        if(yz(d)) sl++;
        return;
    }
    if(b >= n) return;
    jf(b + 1, c + 1, d + a[b]);
    jf(b + 1, c, d);
}

int main()
{
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        int i1;
        cin >> i1;
        a.push_back(i1);
    }
    jf(0,0,0);
    cout << sl;
    return 0;
}