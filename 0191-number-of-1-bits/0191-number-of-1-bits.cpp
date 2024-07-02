class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n) 
        {
            n &= (n - 1); // Flip the least significant set bit to 0
            count++;
        }
        return count;
    }
};