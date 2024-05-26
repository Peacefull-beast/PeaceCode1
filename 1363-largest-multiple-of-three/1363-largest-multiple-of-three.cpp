class Solution {
public:
    string largestMultipleOfThree(vector<int>& digit) {
        int n = digit.size();
        int sum = 0;

        for(auto &ele:digit)
        {
            sum += ele;
        }

        sort(digit.begin(),digit.end());
        //reverse(digit.begin(),digit.end());

        if(sum % 3 == 1)
        {
            bool flag = false;
            for(int i = 0;i<digit.size();i++)
            {
                if(digit[i] % 3 == 1)
                {
                    flag = true;
                    digit[i] = -1;
                    break;
                }
            }
            if(flag == false)
            {
                int count = 0;
                for(int i = 0;i<digit.size();i++)
                {
                    if(digit[i] % 3 == 2)
                    {
                        count++;
                        flag = true;
                        digit[i] = -1;
                        if(count == 2)
                        break;
                    }
                }
                if(count != 2)
                {
                    return "";
                }
            }
        }
        else if(sum % 3 == 2)
        {
            bool flag = false;
            for(int i = 0;i<digit.size();i++)
            {
                if(digit[i] % 3 == 2)
                {
                    flag = true;
                    digit[i] = -1;
                    break;
                }
            }
            if(flag == false)
            {
                int count = 0;
                for(int i = 0;i<digit.size();i++)
                {
                    if(digit[i] % 3 == 1)
                    {
                        count++;
                        flag = true;
                        digit[i] = -1;
                        if(count == 2)
                        break;
                    }
                }
                if(count != 2)
                {
                    return "";
                }
            }
        }

        string ans = "";
        for(int i = digit.size()-1 ; i >=0 ;i--)
        {
            if(digit[i] != -1)
            ans += to_string(digit[i]);
        }

        return ans[0] == '0' ? "0" : ans;
    }
};