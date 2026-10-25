#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool ai(string s)
{
    stack<char> st;
    for(char i : s)
    {
        if(i == '(')
        {
            st.push(i);
        }
        else if(i == ')')
        {
            if(st.empty()) return false;
            else st.pop();
        }
    }
    if(st.empty()) return true;
    else return false;
}

int main()
{
    string s;
    cin >> s;
    if(ai(s)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}