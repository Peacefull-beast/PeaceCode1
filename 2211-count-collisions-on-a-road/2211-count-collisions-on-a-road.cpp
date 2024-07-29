class Solution {
public:
    int countCollisions(string directions) {
        int ans = 0; 
        stack<char> st;
        
        for (auto d : directions) {
            if (d == 'L') 
            {
                if (!st.empty() && st.top() == 'R') 
                {
                    
                    while (!st.empty() && st.top() == 'R') 
                    {
                        ans++;
                        st.pop();
                    }
                    
                    ans++;
                    st.push('S');
                } 
                else if (!st.empty() && st.top() == 'S')
                    ans++;
                
                else 
                    st.push(d);
            } 
            else if (d == 'R') 
                st.push(d);
            else if (d == 'S') 
            {
                if (!st.empty() && st.top() == 'R') 
                {
                
                    while (!st.empty() && st.top() == 'R') 
                    {
                        ans++;
                        st.pop();
                    }
                }
                st.push(d);
            }
        }
        
        return ans;
    }
};
