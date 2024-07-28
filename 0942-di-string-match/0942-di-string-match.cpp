class Solution {
public:
    vector<int> diStringMatch(string s) 
    {
        vector<int>ans;
        stack<int>st;
        
        for(int i=0 ;i<=s.length(); i++)
        {
            st.push(i);
            if(i == s.size() || s[i] == 'I')
            {
                while(!st.empty())
                {
                    ans.push_back(st.top());
                    st.pop();
                }
            }
        }
        return ans;
    }
};