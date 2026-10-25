#include <iostream>
#include <string>
using namespace std;

int main()
{
    int a;
    string str;
    cin >> a >> str;
    while (a--)
    {
        int op;
        cin >> op;
        if(op == 1)
        {
            string js;
            cin >> js;
            str = str + js;
            cout << str << endl;
        }
        else if(op == 2)
        {
            int a1,a2;
            cin >> a1 >> a2;
            str = str.substr(a1, a2);//从下标 a1 开始取 a2 个
            cout << str << endl;
        }
        else if(op == 3)
        {
            int ab;
            string cr;
            cin >> ab >> cr;
            str.insert(ab,cr);// 在 ab 处插入 cr
            cout << str << endl;
        }
        else if(op == 4)
        {
            string cz;
            cin >> cz;
            cout << (int)str.find(cz) << endl;// 找不到返回 string::npos（转 int 是 -1）
        }
    }
    return 0;
}