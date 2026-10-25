#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student { int a;  int b; int c;};

bool bj( Student s, Student t)
{
    if(s.c != t.c) return s.c > t.c;
    else if(s.b != t.b) return s.b > t.b;
    else return s.a < t.a;
}

int main()
{
    int rx;
    cin >> rx;
    vector<Student> a;
    for(int i = 0; i < rx; i++)
    {
        int a1,a2,a3;
        cin >> a1 >> a2 >> a3;
        a.push_back({i+1,a1,a1+ a2+ a3});
    }
    sort(a.begin(), a.end(), bj);
    for(int i = 0; i < 5; i++)
    {
        cout << a[i].a << " " << a[i].c << endl;
    }
    return 0;
}