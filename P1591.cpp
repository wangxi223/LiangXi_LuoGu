#include <cstddef>
#include <iostream>
#include <vector>
using namespace std;

vector<int> chenfa(int n)
{
    int carry = 0;
    vector<int> s{1};
    for(int i = 2; i <= n; i++)
    {
        carry = 0;
        for(size_t k = 0; k < s.size(); k++)
        {
            s[k] = s[k] * i + carry;
            carry = s[k] / 10;
            s[k] = s[k] % 10;
        }
        while(carry > 0)
        {
            s.push_back(carry % 10);
            carry /= 10;
        }
    }
    return s;
}

int main()
{
    int t, n, a;
    vector<int> cc;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        cin >> n >> a;
        int js = 0;
        vector<int> op = chenfa(n);
        for(size_t k = 0; k < op.size(); k++)
        {
            if(op[k] == a) js++;
        }
        cc.push_back(js);
    }
    for(size_t i = 0; i < cc.size(); i ++)
    {
        cout << cc[i] << endl;
    }
    return 0;
}