#include <bits/stdc++.h>
using namespace std;

struct bian
{
    int u, v, w;
};

auto Merge(vector<bian>& tu, int l, int r, int mid)
{
    vector<bian> tem(r - l);
    int i = l, j = mid, k = 0;
    while(i < mid && j < r)
    {
        if(tu[i].w <= tu[j].w) tem[k++] = tu[i++];
        else tem[k++] = tu[j++];
    }
    while(i < mid) tem[k++] = tu[i++];
    while(j < r) tem[k++] = tu[j++];
    for(int p = 0; p < k; p++) tu[l + p] = tem[p];
}

auto MergeQurt(vector<bian>& tu, int l, int r)
{
    if(r - l <= 1) return;
    int x = l, y = r, z = (l + r) / 2;
    MergeQurt(tu, x, z);
    MergeQurt(tu, z, y);
    Merge(tu, x, y, z);
    return;
}

auto Find(vector<int>& biao, int a)
{
    if(biao[a] == a) return a;
    return biao[a] = Find(biao, biao[a]);
}

auto Ka(vector<bian>& tu, int shuliang)
{
    vector<int> biao(shuliang + 1);
    for(int i = 0; i <= shuliang; i++) biao[i] = i;
    MergeQurt(tu, 0, tu.size());
    int ans = 0, tem = 0;
    for(int i = 0; i < tu.size(); i++)
    {
        int a = Find(biao, tu[i].u), b = Find(biao, tu[i].v);
        if(a != b)
        {
            biao[b] = a;
            ans += tu[i].w;
            tem++;
        }
        if(tem == shuliang - 1) break;
    }
    if(tem != shuliang - 1) return -1;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<bian> tu;
    for(int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        tu.push_back({x, y, z});
    }
    int lll = Ka(tu, n);
    if(lll == -1) cout << "orz" << endl;
    else cout << lll << endl;
    return 0;
}