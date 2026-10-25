#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Stude {string cj; int yw; int sx; int yy; int id;};

bool bj(Stude a, Stude b)
{
    if(a.yw + a.sx + a.yy != b.yw + b.sx + b.yy) return a.yw + a.sx + a.yy > b.yw + b.sx + b.yy;
    else return a.id < b.id;
}

int main()
{
    int a;
    cin >> a;
    vector<Stude> b;
    for(int i = 0; i < a; i++)
    {
        string a1;
        int a2, a3, a4;
        cin >> a1 >> a2 >> a3 >> a4;
        b.push_back({a1, a2, a3, a4, i});
    }
    sort(b.begin(), b.end(), bj);
    cout << b[0].cj << " " << b[0].yw << " " << b[0].sx << " " << b[0].yy << endl;
    return 0;
}
