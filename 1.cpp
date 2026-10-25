#include <iostream>
using namespace std;

int main()
{
    char a;
    cin >> a;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 2 - i; j++)
        {
            cout << " ";
        }
        for(int k = 0; k < (i + 1)*2-1; k++)
        {
            cout << a;
        }
        cout << endl;
    }
    return 0;
}