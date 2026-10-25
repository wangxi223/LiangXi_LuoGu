#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    vector<int> op(n + 1);
    vector<int> f(n + 1, 0); // 默认找不到就是0
    
    for(int i = 1; i <= n; i++) cin >> op[i];
    
    stack<int> st; // 单调栈，存的是下标
    for(int i = n; i >= 1; i--) // 从右往左遍历
    {
        // 把栈里比当前元素矮的全部弹出去
        while(!st.empty() && op[st.top()] <= op[i]) 
        {
            st.pop();
        }
        
        // 此时栈顶就是第一个比 op[i] 大的数的下标
        if(!st.empty()) 
        {
            f[i] = st.top();
        }
        
        // 把当前下标入栈
        st.push(i); 
    }
    
    for(int i = 1; i <= n; i++) cout << f[i] << " ";
    
    return 0;
}