class Solution {
public:
    int solve( int ind, vector<int>& tokens, int power, int score)
    {
        if(ind >= tokens.size())
            return 0;
        int fup = 0;
        int fdo = 0;
        
        if(power >= tokens[ind])
        fup = solve(ind+1, tokens, power-tokens[ind], score+1)+1;
        else if(score>=1)
        fdo = solve(ind+1, tokens, power+tokens[ind], score-1)-1;
        
        return max(fup, fdo);
    }
        int bagOfTokensScore(vector<int>& tokens, int power) 
        {
            int score = 0;
            int max_sc = 0;
            sort(tokens.begin(), tokens.end());
            
            int i = 0; int j = tokens.size()-1;
            while(i<=j)
            {
                if(power >= tokens[i])
                {
                    score++;
                    max_sc = max(max_sc, score);
                    power-=tokens[i];
                    i++;
                }
                else if(score >= 1)
                {
                    score--;
                    max_sc = max(max_sc, score);
                    power+=tokens[j];
                    j--;
                }
                
                else
                    return max_sc;
            }
            
            return max_sc;
    }
};