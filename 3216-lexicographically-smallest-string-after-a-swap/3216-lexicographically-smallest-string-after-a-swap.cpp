class Solution {
public:
    string getSmallestString(string s) 
    {
        for(int i=1; i<s.length(); i++)
        {
            int n1 = s[i-1]-'0';
            int n2 = s[i] - '0';
            
            if((n1%2 == 0) && (n2%2 == 0) && (n1 > n2) || (n1%2 != 0) && (n2%2 != 0) && n1 > n2)
            {
                swap(s[i], s[i-1]);
                break;
            }
        }
        
        return s;
    }
};