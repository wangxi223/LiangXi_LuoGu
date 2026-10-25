#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    priority_queue<int,vector<int>,greater<int>> s;
    int a, d = 0;
    cin >> a;
    for(int i = 0; i < a; i++)
    {
        int ls;
        cin >> ls;
        s.push(ls);
    }
    while(s.size() > 1)
    {
        int b = s.top();
        s.pop();
        int c = s.top();
        s.pop();
        s.push(b + c);
        d += b + c;
    }
    cout << d;
    return 0;
}