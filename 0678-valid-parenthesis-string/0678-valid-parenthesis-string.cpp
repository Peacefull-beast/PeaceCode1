class Solution {
public:
    bool checkValidString(string s) 
    {
        stack<int>s1;
        stack<int>s2;
        
        for(int i = 0; i<s.length(); i++)
        {
            if(s[i] == '(')
                s1.push(i);
            else if(s[i] == '*')
                s2.push(i);
            else
            {
                if(s1.empty() != true)
                    s1.pop();
                else if(s2.empty() != true)
                    s2.pop();
                else
                 return false;
            }
        }
        
        while(s1.empty() != true)
        {
            if(s2.empty() == true)
                return false;
            else if(s1.top() > s2.top())
                return false;
            else
            {
                s1.pop();
                s2.pop();
            }
        }
        return true;
    }
};