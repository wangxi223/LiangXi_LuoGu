#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int n, r;
vector<int> abc;

void dfs(int star)
{
    if(abc.size() == r)
    {
        for(int i : abc)
        {
            cout << setw(3) << i;
        }
        cout << endl;
        return;
    }
    for(int i = star; i <= n; i++)
    {
        abc.push_back(i);
        dfs(i+1);
        abc.pop_back();
    }
}

int main()
{
    cin >> n >> r;
    dfs(1);
    return 0;
}