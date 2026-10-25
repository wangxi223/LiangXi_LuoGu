#include <functional>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    priority_queue<int> big;
    priority_queue<int , vector<int>, greater<int>> small;
    for(int i = 0; i < n; i++)
    {
        int sr;
        cin >> sr;
        big.push(sr);
        small.push(big.top());
        big.pop();
        if(small.size() > big.size())
        {
            big.push(small.top());
            small.pop();
        }
        if(i % 2 == 0) cout << big.top() << endl;
    }
    return 0;
}