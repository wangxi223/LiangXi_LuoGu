#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void sgiyi(int win, string jg)
{
    int w = 0;int l = 0;
    for(char i : jg)
    {
        if(i == 'E') break;
        if(i == 'W') w++;
        if(i == 'L') l++;
        if((w >= win || l >= win) && abs(w - l) >= 2)
        {
            cout << w << ":" << l << endl;
            w = 0;l = 0;
        }
    }
    cout << w << ":" << l << endl;
}

int main()
{
    string jg, ling;
    while (cin >> ling)
    {
        jg += ling;
        if(ling.empty()) break;
    }
    sgiyi(11, jg);
    cout << endl;
    sgiyi(21, jg);
    return 0;
}