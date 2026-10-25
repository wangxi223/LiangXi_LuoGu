#include <iostream>
using namespace std;

int sgl[1001];//记忆化算法

int wx(int x)
{
    if(sgl[x]) return sgl[x];
    int shuliang = 1;
    for(int i = 1; i <= x/2; i++)
    {
        shuliang += wx(i);
    }
    sgl[x] = shuliang;
    return shuliang;
}

int main()
{
    int x, shuliang = 0;
    cin >> x;
    if(x <= 1000 && x >= 1)
    {
        cout << wx(x);
    }
    return 0;
}