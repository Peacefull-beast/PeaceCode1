class Solution {
public:
    string makeGood(string s) 
    {
        stack<char>st;
        st.push(s[0]);
        for(int i = 1;i<s.length();i++)
        {
              if(st.empty() == true)
                  st.push(s[i]);
              else if(abs(st.top() - s[i]) == (97-65))
                  st.pop();
              else
                  st.push(s[i]);
            
        }
        string str="";
        while(st.empty() != true)
        {
            str = st.top() + str;
            st.pop();
        }
        return str;
    }
};