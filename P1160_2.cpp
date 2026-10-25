#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    for(int i = 2; i <= n; i++)
    {
        int k, p;
        cin >> k >> p;
        if(p == 0)
        {
            if(a[k] != 0)
            {
                a[i] = a[k];
                b[a[k]] = i;
            }
            a[k] = i;
            b[i] = k;
        }
        if(p == 1)
        {
            if(b[k] != 0)
            {
                b[i] = b[k];
                a[b[k]] = i;
            }
            b[k] = i;
            a[i] = k;
        }
    }
    int sc;
    cin >> sc;
    for(int i = 0; i < sc; i++)
    {
        int ws;
        cin >> ws;
        b[a[ws]] = b[ws];
        a[b[ws]] = a[ws];
        a[ws] = 0; b[ws] = 0;
    }
    int abc;
    for(int i = 0; i < n + 1; i++)
    {
        if(a[i] == 0 && b[i] != 0)
        {
            abc = i;
            break;
        }
    }
    while (b[abc] != 0)
    {
        cout << abc << " ";
        abc = b[abc];
    }
    cout << abc << endl;
    return 0;
}