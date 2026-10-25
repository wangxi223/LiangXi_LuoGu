#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void quickSort(vector<int>& a, int l, int r)
{
    if(l > r) return;
    int i = l;
    int j = r;
    int mid = (l + r) / 2;
    int p = a[mid];
    while(i <= j)
    {
        while(a[i] < p) i++;
        while(a[j] > p) j--;
        if(i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if(l < j) quickSort(a, l, j);
    if(i < r) quickSort(a, i, r);
    return;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        int ls;
        cin >> ls;
        a.push_back(ls);
    }
    quickSort(a, 0, a.size() - 1);
    for(int i : a) cout << i << " ";
    return 0;
}