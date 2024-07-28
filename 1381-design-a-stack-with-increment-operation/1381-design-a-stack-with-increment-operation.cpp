#include<bits/stdc++.h>
class CustomStack {
public:
    stack<int> st;
    int size;
    int temp;
    CustomStack(int maxSize) 
    {
        size = maxSize;
        temp = 0;
    }
    
    void push(int x) 
    {
        if(temp < size)
        {
            st.push(x);
            temp++;
        }
    }
    
    int pop() 
    {
        if(temp > 0)
        {
            int t = st.top();
            st.pop();
            temp--;
            return t;
        }
        
        return -1;
    }
    
    void increment(int k, int val) 
    {
        stack<int>s;
        while(!st.empty())
        {
            s.push(st.top());
            st.pop();
        }
        while(!s.empty() && k > 0)
        {
            st.push(s.top() + val);
            s.pop();
            k--;
        }
        while(!s.empty())
        {
            st.push(s.top());
            s.pop();
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */