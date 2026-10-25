#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int n;
vector<int> jg;
bool used[9];

void dfs()
{
    if(jg.size() == n)
    {
        for(int i : jg)
        {
            cout << setw(5) << i;
        }
        cout << endl;
        return;
    }
    for(int i = 1; i <= n; i++)
    {
        if(used[i]) continue;
        used[i] = true;
        jg.push_back(i);
        dfs();
        jg.pop_back();
        used[i] = false;
    }
}

int main()
{
    cin >> n;
    dfs();
    return 0;
}