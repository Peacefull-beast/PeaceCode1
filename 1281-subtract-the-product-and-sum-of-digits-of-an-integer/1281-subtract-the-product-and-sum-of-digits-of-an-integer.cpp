class Solution {
public:
    int subtractProductAndSum(int num) 
    {
        long long sum = 0; 
        long long pro = 1;
        
        while(num!=0)
        {
            int d = num%10;
            sum += d;
            pro *= d;
            
            num /= 10;
        }
        
        return pro-sum;
        
    }
};