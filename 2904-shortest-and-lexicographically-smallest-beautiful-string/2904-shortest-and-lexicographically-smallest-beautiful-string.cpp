#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) 
    {
        string temp = "";
        int i = 0; 
        int j = 0;
        int freq = 0;
        int minLength = INT_MAX;
        
        while(j < s.length())
        {
            if(s[j] == '1')
                freq++;
            
            while(freq > k)
            {
                if(s[i] == '1')
                    freq--;
                i++;
            }
            while(s[i]!='1' && i <= j)i++;
            if(freq == k)
            {
                
                string current = s.substr(i, j - i + 1);
                if(current.length() < minLength || (current.length() == minLength && current < temp))
                {
                    minLength = current.length();
                    temp = current;
                }
            }
            
            j++;
        }
        
        return temp.empty() ? "" : temp;
    }
};
