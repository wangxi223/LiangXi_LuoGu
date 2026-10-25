#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    int shuliang;
    cin >> shuliang;
    vector<int> a(shuliang);
    for(int i = 0; i < shuliang; i++)
    {
        cin >> a[i];
    }
    set<int> b(a.begin(),a.end());
    cout << b.size() << endl;
    for(int i : b)
    {
        cout << i << " ";
    }
    return 0;
}