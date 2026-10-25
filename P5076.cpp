#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node
{
    int val;
    Node* left;
    Node* rightl;
    Node(int v) : val(v), left(nullptr), rightl(nullptr) {}
};

vector<int> zx_bianli(Node* n, vector<int>& x)
{
    if(n == nullptr) return x;
    if(n->left != nullptr) zx_bianli(n->left, x);
    x.push_back(n->val);
    if(n->rightl != nullptr) zx_bianli(n->rightl, x);
    return x;
}

int paiming(Node* n, int x)
{
    vector<int> y;
    y = zx_bianli(n, y);
    int op;
    for(op = 0; op < y.size(); op++)
    {
        if(y[op] >= x) break;
    }
    return op + 1;
}

int caxun(Node* n, int x)
{
    vector<int> y;
    y = zx_bianli(n, y);
    if(x <= y.size()) return y[x - 1];
    return 0;
}

int qiangqu(Node* n, int x)
{
    vector<int> y;
    y = zx_bianli(n, y);
    int sc;
    if(y.size() <= 1 || y[0] >= x) return -2147483647;
    else for(int i : y) if(i < x) sc = i;
    return sc;
}

int hoqu(Node* n, int x)
{
    vector<int> y;
    y = zx_bianli(n, y);
    for(int i : y)
    {
        if(i > x) return i;
    }
    return 2147483647;
}

void BST_cr(Node*& n, int x)
{
    if(n == nullptr)
    {
        n = new Node(x);
        return;
    }
    if(x >= n->val)
    {
        if(n->rightl != nullptr) BST_cr(n->rightl, x);
        else n->rightl = new Node(x);
    }
    if(x < n->val)
    {
        if(n->left != nullptr) BST_cr(n->left, x);
        else n->left = new Node(x);
    }
    return;
}

void sc(Node*& n)
{
    if(n == nullptr) return;
    queue<Node*> a;
    a.push(n);
    while (!a.empty())
    {
        Node* wer = a.front();
        a.pop();
        if(wer->left != nullptr) a.push(wer->left);
        if(wer->rightl != nullptr) a.push(wer->rightl);
        delete wer;
    }
    n = nullptr;
    return;
}

int main()
{
    int cx;
    cin >> cx;
    Node* n = nullptr;
    for(int i = 0; i < cx; i++)
    {
        int xx, sr;
        cin >> xx >> sr;
        if(xx == 1) cout << paiming(n, sr) << endl;
        if(xx == 2) cout << caxun(n, sr) << endl;
        if(xx == 3) cout << qiangqu(n, sr) << endl;
        if(xx == 4) cout << hoqu(n, sr) << endl;
        if(xx == 5) BST_cr(n, sr);
    }
    sc(n);
    return 0;
}