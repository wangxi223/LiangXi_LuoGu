#include <iostream>
#include <vector>
using namespace std;

int ans = 0, M, N;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int SX, int SY, int FX, int FY, vector<int> qipang[])
{
    if(SX == FX && SY == FY)
    {
        ans++;
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        int x = SX + dx[i];
        int y = SY + dy[i];
        if(x < 1 || x > N || y < 1 || y > M) continue;
        if(qipang[x][y] == 0)
        {
            qipang[x][y] = 1;
            dfs(x, y, FX, FY, qipang);
            qipang[x][y] = 0;
        }
    }
    return;
}

int main()
{
    int SX, SY, FX, FY, T;
    cin >> N >> M >> T >> SX >> SY >> FX >> FY;
    vector<int> qipang[N + 1];
    for(int i = 0; i < N + 1; i++) qipang[i].assign(M + 1, 0);
    for(int i = 0; i < T; i++)
    {
        int TX, TY;
        cin >> TX >> TY;
        qipang[TX][TY] = -1;
    }
    qipang[SX][SY] = 1;
    dfs(SX, SY, FX, FY, qipang);
    cout << ans << endl;
    return 0;
}