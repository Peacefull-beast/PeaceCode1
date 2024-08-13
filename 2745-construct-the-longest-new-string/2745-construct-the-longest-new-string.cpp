class Solution {
public:
    
    int longestString(int x, int y, int z) 
    {
        
        if(x == y)
            return 2*(x+y+z);   //AABB*X + AB*Z
        
        else
            return 2 * (2 * min(x, y) + 1 + z); // AABB*(min(x,y)) + AB*z
    }
};
