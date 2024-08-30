class Solution {
public:
    int calculate(string s) 
    {
        int n = s.length();
        stack<int>st;
        int num = 0;
        int res = 0;
        int sgn = 1;
        for(int i=0; i<n; i++)
        {
            if(isdigit(s[i]))
            num = num * 10 + (s[i]-'0');

            else if(s[i] == '+')
            {
                res += (num*sgn);
                num = 0;
                sgn = 1;
            }
            else if(s[i] == '-')
            {
                res += (num * sgn);
                num = 0;
                sgn = -1;
            }
            else if(s[i] == '(')
            {
                st.push(res);
                st.push(sgn);
                res = 0;
                sgn = 1;
            }
            else if(s[i] == ')')
            {
                res += (num * sgn); 
                num = 0; 
                int prevSign = st.top(); st.pop(); 
                int prevRes = st.top(); st.pop();  
                res = prevRes + (prevSign * res);
            }
        }
        res += (num*sgn);
        return res;
    }
};