class Solution {
public:
    int totalMoney(int n) 
    {
        
        
        int n_weeks = n/7;
        int r_days = n%7;
        
        if(n_weeks == 0)
            return (r_days*(r_days+1))/2;
        
        int amt = 28*n_weeks + 7*((n_weeks-1)*n_weeks)/2;
        int temp = (r_days*(r_days+1))/2 + r_days*n_weeks;
        
        return amt+temp;
    }
};