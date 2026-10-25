#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* next;
};

void wcf(int a, Node*& b)
{
    Node* n =new Node{a, nullptr};
    if(b == nullptr)
    {
        b = n;
        return;
    }
    else
    {
        Node* cur = b;
        while (cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = n;
    }
    return;
}

void sc(int a, Node*& b)
{
    if(b == nullptr) return;
    if(b->next ==nullptr)
    {
        cout << b->val << " ";
        delete b;
        b = nullptr;
        return;
    }
    if (a == 1)
    {
        while (b->next != b)
        {
            Node* abc = b->next;
            cout << abc->val << " ";
            b->next = abc->next;
            delete abc;
            abc = nullptr;
        }
        cout << b->val << " ";
        delete b;
        b = nullptr;
        return;
    }
    int js = 1;
    Node* cur = b->next;
    while (b->next != b)
    {
        cur = b->next;
        if(js == a)
        {
            b->next = cur->next;
            cout << cur->val << " ";
            delete cur;
            js = 1;
        }
        b = b->next;
        js++;
    }
    cout << b->val << " ";
    delete b;
    b = nullptr;
    return;
}

int main()
{
    int m, n;
    cin >> n >> m;
    Node* a = nullptr;
    for(int i = 1; i <= n; i++)
    {
        wcf(i, a);
    }
    if(a->next != nullptr)
    {
        Node* b = a;
        while (a->next != nullptr)
        {
            a = a->next;
        }
        a->next = b;
    }
    sc(m, a);
    return 0;
}