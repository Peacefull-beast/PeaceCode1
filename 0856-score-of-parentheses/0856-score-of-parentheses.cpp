class Solution {
public:
    
    int scoreOfParentheses(string s) 
    {
        int score = 0;
        stack<int>st;
        
        for(auto c:s)
        {
            if(c == '(')
            {
                st.push(score);
                score = 0;
            }
            
            else
            {
                int t = st.top();
                score = t + max(2*score,1);
                st.pop();
            }
        }
        return score;
    }
};