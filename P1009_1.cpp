#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>//洛谷不支持boost库，使用时请注意
using namespace std;
using namespace boost::multiprecision;

cpp_int af(int abc)
{
    if(abc==1) return 1;
    cpp_int b = 1;
    for(int i = 1; i <= abc; i++)
    {
        b= b*i;
    }
    int abc1 = abc;
    b = b + af(abc1 - 1);
    return b;
}

int main()
{
    int a;
    cin >> a;
    cout << af(a);
    return 0;
}