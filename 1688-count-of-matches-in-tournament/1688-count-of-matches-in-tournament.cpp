class Solution {
public:
    int numberOfMatches(int n) 
    {
        int temp = 0;
        int ans = 0;
        
        while(n!=0)
        {
            n+=temp;
            if(n%2 != 0)
            {
                temp=1;
                n-=1;  
            }
            else
                temp = 0;
            ans += (n/2);
            n/=2;
        }
        
        return ans;
    }
};