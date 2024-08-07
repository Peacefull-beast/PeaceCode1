class Solution {
public:
    
    int numTeams(vector<int>& rating) 
    {
        int n = rating.size();
              
        int teams = 0;
        
        for(int j=1; j < n-1; j++)
        {
            int csl = 0;
            int csr = 0;
            int cll = 0;
            int clr = 0;
            
            
            for(int i=0; i<j; i++)
            {
                if(rating[i] < rating[j])
                    csl++;
                else if(rating[i] > rating[j])
                    cll++;  
            }
            
            for(int i=j+1; i<n; i++)
            {
                if(rating[j] < rating[i])
                    clr++;
                else if(rating[j] > rating[i])
                    csr++;  
            }
            
            teams += (cll*csr) + (clr*csl);
            
        }
        
        return teams;
    }
};