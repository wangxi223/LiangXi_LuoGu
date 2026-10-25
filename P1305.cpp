#include <iostream>
#include <queue>
using namespace std;

struct tree
{
    char val;
    tree* left;
    tree* right;
};

void bianli_cr(tree* n, char x[3])
{
    if(n == nullptr) return;
    queue<tree*> a;
    a.push(n);
    while (!a.empty())
    {
        tree* wer = a.front();
        a.pop();
        if(wer->val == x[0])
        {
            if(x[1] != '*')
            {
                tree* k = new tree{x[1], nullptr,nullptr};
                wer->left = k;
            }
            if(x[2] != '*')
            {
                tree* l = new tree{x[2], nullptr, nullptr};
                wer->right = l;
            }
            return;
        }
        if(wer->left != nullptr) a.push(wer->left);
        if(wer->right != nullptr) a.push(wer->right);
    }
    return;
}

void bainli(tree* n)
{
    cout << n->val;
    if(n->left != nullptr)
    {
        tree* wer = n->left;
        bainli(wer);
    }
    if(n->right != nullptr)
    {
        tree* wer = n->right;
        bainli(wer);
    }
    return;
}

void sc(tree*& n)
{
    if(n == nullptr) return;
    queue<tree*> a;
    a.push(n);
    while (!a.empty())
    {
        tree* wer = a.front();
        a.pop();
        if(wer->left != nullptr) a.push(wer->left);
        if(wer->right != nullptr) a.push(wer->right);
        delete wer;
        wer = nullptr;
    }
    n = nullptr;
    return;
}

int main()
{
    int n1;
    cin >> n1;
    if(n1 <= 0) return 0;
    char n[3];
    cin >> n[0] >> n[1] >> n[2];
    tree* a = new tree{n[0], nullptr, nullptr};
    bianli_cr(a, n);
    for(int i = 0; i < n1 - 1; i++)
    {
        cin >> n[0] >> n[1] >> n[2];
        bianli_cr(a, n);
    }
    bainli(a);
    sc(a);
    return 0;
}