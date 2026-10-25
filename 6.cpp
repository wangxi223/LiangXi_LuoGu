#include <iostream>
#include <map>
using namespace std;

int main()
{
    int shuliang;
    cin >> shuliang;
    map<int,bool> a;
    for(int i = 1; i < shuliang; i++)
    {
        a[i] = true;
    }
    for(int i = 1; i < shuliang; i++)
    {
        for(int k = i; k < shuliang; k+=i)
        {
            a[k] = !a[k];
        }
    }
    for(int i = 1; i < shuliang; i++)
    {
        if(!a[i]) cout << i << " ";
    }
    return 0;
}