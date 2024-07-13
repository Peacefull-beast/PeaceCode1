class Solution {
public:
    string sortVowels(string s) 
    {
        vector<char>vow;
        vector<int>ind;
        int i = 0;
        for(auto ch : s)
        {
            if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
            {
                vow.push_back(ch);
                ind.push_back(i);
            }
            else if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
            {
                vow.push_back(ch);
                ind.push_back(i);
            }
            i++;
        }
        
        sort(vow.begin(), vow.end());
        int p = 0;
        for (int i = 0; i < ind.size(); ++i)
        {
            s[ind[i]] = vow[i];
        }

        
        return s;
    }
};