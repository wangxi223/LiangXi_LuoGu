#include <iostream>
using namespace std;

struct Node
{
    int val;
    Node* prev;
    Node* next;
};

void charu(int k, int p, int a,Node*& n)
{
    Node* ls = new Node{a, nullptr, nullptr};
    Node* cur = n;
    while (cur->val != k)
    {
        if(cur->next == nullptr) return;
        cur = cur->next;
    }
    if(p == 0)
    {
        if(cur->prev == nullptr)
        {
            ls->next = cur;
            cur->prev = ls;
            n = n->prev;
        }
        else
        {
            Node* abc = cur->prev;
            abc->next = ls;
            ls->prev = abc;
            ls->next = cur;
            cur->prev = ls;
        }
    }
    else
    {
        if(cur->next == nullptr)
        {
            cur->next = ls;
            ls->prev =cur;
        }
        else
        {
            Node* abc = cur->next;
            cur->next = ls;
            ls->prev = cur;
            ls->next = abc;
            abc->prev = ls;
        }
    }
    return;
}

void sc(int a, Node*& n)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    if(n == nullptr) return;
    Node* cur = n;
    if(cur->val == a)
    {
        n = n->next;
        delete cur;
        cur = nullptr;
        if(n != nullptr)
        {
            n->prev = nullptr;
        }
        return;
    }
    if(cur->val != a && cur->next != nullptr)
    {
        while(cur->next != nullptr)
        {
            if(cur->next->val == a) break;
            cur = cur->next;
        }
    }
    if(cur->next == nullptr) return;
    if(cur->next->next == nullptr)
    {
        Node* ls = cur;
        cur = cur->next;
        ls->next = nullptr;
        delete cur;
        cur = nullptr;
    }
    else
    {
        Node* ls = cur;
        ls = ls->next;
        cur->next = ls->next;
        ls->next->prev = cur;
        delete ls;
        ls = nullptr;
    }
    return;
}

int main()
{
    int n, k, p, o;
    cin >> n;
    Node* a = new Node{1, nullptr, nullptr};
    for(int i = 2; i <= n; i++)
    {
        cin >> k >> p;
        charu(k, p, i, a);
    }
    cin >> o;
    for(int i = 0; i < o; i++)
    {
        int op;
        cin >> op;
        sc(op, a);
    }
    if(a == nullptr) return 0;
    Node* b = a;
    while (b->next != nullptr)
    {
        cout << b->val << " ";
        b = b->next; 
    }
    cout << b->val;
    while (a->next != nullptr)
    {
        Node* c = a;
        a = a->next;
        delete c;
        c = nullptr;
    }
    delete a;
    a = nullptr;
    return 0;
}