class Solution {
public:
    bool isValid(string s) 
    {
        stack<char>st;
        int i = 0;
        while(i < s.length())
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            
            else if(st.empty() == true && (s[i] == ')' || s[i] == '}' || s[i] == ']'))
                return false;
            
            else if(s[i] == ')' && st.top() == '(' || s[i] == '}' && st.top() == '{' || s[i] == ']' && st.top() == '[')
                st.pop();
            
            else return false;
            i++;
        }
        if(st.empty())
            return true;
        else return false;
    }
};