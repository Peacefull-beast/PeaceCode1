class Solution {
public:
    int minBitFlips(int start, int goal) 
    {
    int xor_value = start ^ goal;

    return std::bitset<32>(xor_value).count();
    }
};