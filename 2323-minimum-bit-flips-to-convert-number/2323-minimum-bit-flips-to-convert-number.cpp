class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
    int xor_value = start ^ goal;

    return bitset<32>(xor_value).count();
    }
};