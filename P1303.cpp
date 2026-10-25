#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> cf(vector<int>& a, vector<int>& b)
{
    vector<int> c(a.size() + b.size(), 0);
    for(int i = 0; i < a.size(); i++)
    {
        for(int k = 0; k < b.size(); k++)
        {
            c[i + k] += a[i] * b[k];
        }
    }
    for(int i = 0; i < c.size() - 1; i++)
    {
        c[i + 1] += c[i] / 10;
        c[i] = c[i]%10;
    }
    return c;
}

int main()
{
    string a1, b1;
    cin >> a1 >> b1;
    vector<int> a2, b2;
    for(int i = a1.size() - 1; i >= 0; i--) a2.push_back(a1[i] - '0');
    for(int i = b1.size() - 1; i >= 0; i--) b2.push_back(b1[i] - '0');
    vector<int> c = cf(a2, b2);
    int wz = c.size() - 1;
    while(c[wz] == 0 && wz > 0) wz--;
    for(int i = wz; i >= 0; i--) cout << c[i];
    return 0;
}