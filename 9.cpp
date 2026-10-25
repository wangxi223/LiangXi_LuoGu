#include <iostream>
using namespace std;

long long fc(int n, int x)
{
    if(n == 0) return 1;
    else if(n == 1) return 2LL*x;
    else if(n > 1) return 2LL*x*fc(n-1,x) - 2LL*(n-1)*fc(n-2,x);
}

int main()
{
    int n, x;
    cin >> n >> x;
    if(n <= 8 && x <= 8 && n>= 0 && x >= 0) cout << fc(n,x);
    return 0;
}