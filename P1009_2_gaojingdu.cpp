#include <iostream>
#include <vector>
using namespace std;

vector<int> jiafa(vector<int> x, vector<int> y)
{
    int ls;
    if(x.size() > y.size()) ls = x.size(), y.resize(x.size(), 0);
    else ls = y.size(), x.resize(y.size(), 0);
    vector<int> s(ls + 1, 0);
    for(int i = 0; i < ls; i++)
        s[i] = x[i] + y[i];
    for(int i = 0; i < ls; i++)
    {
        if(s[i] >= 10)
        {
            s[i + 1] += s[i] / 10;
            s[i] %= 10;
        }
    }
    while(s.size() > 1 && s.back() == 0) s.pop_back();
    return s;
}

vector<int> cheng_int(vector<int> x, int k)
{
    vector<int> s1(x.size(), 0);
    int carry = 0;
    for(int i = 0; i < x.size(); i++)
    {
        int cur = x[i] * k + carry;
        s1[i] = cur % 10;
        carry = cur / 10;
    }
    while(carry > 0)
    {
        s1.push_back(carry % 10);
        carry /= 10;
    }
    while(s1.size() > 1 && s1.back() == 0) s1.pop_back();
    return s1;
}

vector<int> sf(int abc)
{
    vector<int> b = {1};
    vector<int> sum = {0};
    for(int i = 1; i <= abc; i++)
    {
        b = cheng_int(b, i);
        sum = jiafa(sum, b);
    }
    return sum;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a = sf(n);
    int cc = a.size() - 1;
    while(cc > 0 && a[cc] == 0) cc--;
    for(int i = cc; i >= 0; i--)
        cout << a[i];
    cout << endl;
    return 0;
}