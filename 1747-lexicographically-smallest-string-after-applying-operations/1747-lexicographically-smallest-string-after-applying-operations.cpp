class Solution {
public:
    string ans;
    unordered_set<string>st;


    string option1(string &s, int a)
    {
        for(int i=1; i<s.size(); i+=2)
            s[i] = (s[i] - '0' + a) % 10 + '0';
        return s;
    }


    string option2(string &s, int b)
    {
        string res(s.size(), ' ');
        for(int i=0; i < s.size(); i++)
            res[(i+b) %s.size()] = s[i];
        return res;
    }

    
    string findLexSmallestString(string str, int a, int b) 
    {
        

        unordered_set<string> seen; 
        queue<string> q;
        q.push(str);


        string ans = str;


        while(!q.empty())
        {
            string temp = q.front();
            q.pop();

            ans = min(ans , temp);

            string s1 = option1(temp, a);
            if(st.find(s1) == st.end())
            {
                q.push(s1),
                st.insert(s1);
            }

            string s2 = option2(temp, b);
            if(st.find(s2) == st.end())
            {
                q.push(s2),
                st.insert(s2);
            }

        }
        return ans;
        

        
    }
};