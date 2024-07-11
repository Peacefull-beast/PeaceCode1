class Solution {
public:
    int numWaterBottles(int fill, int ex) 
    {
        int ans = 0;
        int emp = 0;
        while(fill != 0)
        {
            ans += fill;
            emp += fill;
            
            fill = emp/ex;
            emp = emp%ex;
            
        }
        
        return ans;
    }
};