#include <iostream>
using namespace std;

int main()
{
    int cx;
    cin >> cx;
    int s[cx];
    for(int i = 0; i < cx; i++)
    {
        cin >> s[i];
    }
    for(int k = 0; k < cx; k++)
    {
        int a=1;
        int b=0;
        for(int i = 0 ; i < s[k] - 1; i++)
        {
            a = a+b;
            b = a-b;
        }
        cout << a <<endl;
    }
    return 0;
}
