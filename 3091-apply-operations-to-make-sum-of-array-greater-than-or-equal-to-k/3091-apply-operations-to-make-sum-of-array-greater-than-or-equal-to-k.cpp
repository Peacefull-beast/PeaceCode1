class Solution {
public:
    
    int minOperations(int k) {
       int p = sqrt(k), q = (k+p-1)/p; 
        return p + q - 2; 
    }
};