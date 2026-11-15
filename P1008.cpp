#include <bits/stdc++.h>
using namespace std;

vector<int> op(10, 0);//int x[10];

auto cafen(int i)
{
    while(i)
    {
        int x = i % 10;
        if(x == 0) return false;
        else op[x]++;
        if(op[x] > 1) return false;
        i /= 10;
    }
    return true;
}

bool jianyan(int a)
{
    op.assign(10, 0);
    if(!cafen(a)) return false;
    if(!cafen(a * 2)) return false;
    if(!cafen(a * 3)) return false;
    for(int i = 1; i <= 9; i++) if(op[i] != 1) return false;
    return true;
}

int main()
{
    for(int i = 123; i <= 329; i++) if(jianyan(i)) cout << i << " " << i * 2 << " " << i * 3 << '\n';
}