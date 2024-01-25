class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev = 0;
        int ans = 0;
        for(int i = 0;i<bank.size();i++)
        {
            string temp = bank[i];
            int cnt = 0;
            for(int j=0;j<temp.length();j++)
            {
                if(temp[j] == '1')
                    cnt++;
            }
            if(cnt == 0)
                continue;
            else
            {
                ans += cnt*prev;
            }
            prev = cnt;
        }
        return ans;
    }
};