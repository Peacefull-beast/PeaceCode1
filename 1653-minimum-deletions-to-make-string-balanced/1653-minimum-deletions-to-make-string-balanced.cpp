class Solution {
public:
    int minimumDeletions(string s) 
    {
        stack<char>st;
        int cnt = 0;
        
        for(auto ch:s)
        {
            if(st.empty())
                st.push(ch);
            
            
            else if(ch == 'a' && st.top() == 'b')
            {
                cnt++;
                st.pop();
            }
            
            else st.push(ch);
        }
        
        return cnt;
    }
};