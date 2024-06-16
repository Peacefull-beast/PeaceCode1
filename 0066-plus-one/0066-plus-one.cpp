class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
        reverse(digits.begin(), digits.end());
        int c = 1;
        for(int i = 0; i<digits.size(); i++)
        {
            if(digits[i] != 9)
            {
                digits[i] += 1;
                c = 0;
                break;
            }
            else
                digits[i] = 0;
        }
        if(c == 1)
            digits.push_back(c);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};