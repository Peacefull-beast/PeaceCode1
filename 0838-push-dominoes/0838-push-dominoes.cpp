class Solution {
public:
    string pushDominoes(string dominoes) 
    {
        vector<int>left(dominoes.size(), 0);
        vector<int>right(dominoes.size(), 0);
        string str = "";
        
        int cnt = 0;
        char prev = '.';
        
        
        for(int i = 0; i < dominoes.length(); i++)
        {
            if(dominoes[i] == 'R')
            {
                prev = 'R';
                cnt = 1;
                continue;
            }
            else if(dominoes[i] == 'L')
                prev = 'L';
            
            if(prev == 'R' && dominoes[i] == '.')
            {
                right[i] = cnt;
                cnt++;
            }
        }
        
        
        cnt = 1;
        prev = '.';
        for(int i = dominoes.length()-1; i >= 0; i--)
        {
            if(dominoes[i] == 'L')
            {
                prev = 'L';
                cnt = 1;
                continue;
            }
            else if(dominoes[i] == 'R')
                prev = 'R';
            
            if(prev == 'L' && dominoes[i] == '.')
            {
                left[i] = cnt;
                cnt++;
            }
        }
        
        string ans = "";
        
        for(int i = 0; i<dominoes.size(); i++)
        {
            if(dominoes[i] == 'L')
                ans += 'L';
            
            else if(dominoes[i] == 'R')
                ans += 'R';
            
            else if(dominoes[i] == '.')
            {
                if(left[i] == right[i])
                    ans += '.';
                
                else if(right[i] == 0)
                    ans += 'L';
                
                else if(left[i] == 0)
                    ans += 'R';
                
                else if(left[i] < right[i])
                    ans += 'L';
                
                else if(left[i] > right[i])
                    ans += 'R';
            }
        }
        
        return ans;
        
        
        
        
    }
};