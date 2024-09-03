class Solution {
public:
    int getLucky(string s, int k) 
    {
        string str = "";
        for(auto ch : s)
        {
            int t = ch - 'a' +1 ;
            str += to_string(t);
        }
        int sum = 0;
        while (k>0)
        {
            sum = 0;
            string t = str;

            for(auto ch:t)
            sum += ch-'0';
            str = to_string(sum);
            k--;

        }
        return sum;
    }
};