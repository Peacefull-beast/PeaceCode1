class Solution {
public:
    int minOperations(vector<string>& logs) 
    {
        stack<int>st;
        for(auto dir : logs)
        {
            if(dir == "../" )
            {
                if(st.empty() != true)
                    st.pop();
            }
            else if(dir == "./")
                continue;
            else
                st.push(0);
        }
        
        return st.size();
    }
};