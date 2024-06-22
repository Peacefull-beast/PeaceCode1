class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> ls = {-1, -1, -1};
        int i = 0; 
        int cnt = 0;
        
        while(i < s.length())
        {
            ls[s[i] - 'a'] = i;
            if(ls[0] != -1 && ls[1] != -1 && ls[2] != -1)
                cnt += (1 + min({ls[0], ls[1], ls[2]}));
            i++;
        }
        return cnt;
    }
};