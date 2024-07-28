class Solution {
public:
    string removeDuplicates(string s, int k) 
    {
        stack<pair<char,int>>st;
        
        for(auto c: s)
        {            
            if(!st.empty() && st.top().first == c)
            {
                st.top().second += 1;
                if(st.top().second == k)
                    st.pop();
            }
            else
                st.push({c,1});
        }
        
        string ans = "";
        while(!st.empty())
        {
            string temp = "";
            temp.append(st.top().second,st.top().first);
            
            ans = temp + ans;
            st.pop();
        }
        
        return ans;
    }
};