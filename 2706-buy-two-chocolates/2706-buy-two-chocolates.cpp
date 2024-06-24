class Solution {
public:
    int buyChoco(vector<int>& p, int money) 
    {
        sort(p.begin(), p.end());
        int c = money - (p[0]+p[1]) ;
        
        
        if(c>=0)
            return c;
        
        return money;
            
    }
};