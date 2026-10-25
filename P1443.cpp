#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int n, m;
int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {1, -1,2, -2, 2, -2, 1, -1};

void bfs(vector<int> z[], int x, int y)
{
    z[x][y] = 0;
    queue<pair<int, int>> a;
    a.push({x, y});
    while(!a.empty())
    {
        auto [x, y] = a.front();
        a.pop();
        for(int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 1 || nx > n || ny < 1 || ny > m) continue;
            if(z[nx][ny] != -1) continue;
            z[nx][ny] = z[x][y] + 1;
            a.push({nx, ny});
        }
    }
    for(int i = 1; i <= n; i++)
    {
        for(int k = 1; k <= m; k++)
        {
            cout << z[i][k] << " ";
        }
        cout << endl;
    }
    return;
}

int main()
{
    int x, y;
    cin >> n >> m >> x >> y;
    vector<int> qipang[n + 1];
    for(int i = 1; i <= n; i++) qipang[i].assign(m+1, -1);
    bfs(qipang, x, y);
    return 0;
}