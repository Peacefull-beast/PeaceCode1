class Solution {
public:
    bool allzero(vector<int>a)
    {
        for(auto n : a)
            if(n != 0)
                return false;
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        if (s1.length() > s2.length()) 
            return false;

        vector<int> count(26, 0);
        
        for (char ch : s1)
            count[ch-'a']++;

        int window_length = s1.length();

        for (int i = 0; i < s2.length(); i++)
        {
            count[s2[i]-'a']--;
            if(i >= window_length)
                count[s2[i - window_length] - 'a']++;
            if(allzero(count))
                return true;
        }
        return false;

        
    }
};
