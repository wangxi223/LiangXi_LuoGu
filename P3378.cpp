#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    priority_queue<int, vector<int>,greater<int>> a;
    int op;
    cin >> op;
    for(int i = 0; i < op; i++)
    {
        int op1;
        cin >> op1;
        if(op1 == 1)
        {
            int sr;
            cin >> sr;
            a.push(sr);
        }
        if(op1 == 2) cout << a.top() << endl;
        if(op1 ==3) a.pop();
    }
    return 0;
}