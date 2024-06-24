class Solution {
public:
    bool lemonadeChange(vector<int>& bills) 
    {
        int b5 = 0;
        int b10 = 0;
        int b20 = 0;
        bool flag = false;
        for(auto bill : bills)
        {
            if(bill == 5)
                b5 += 1;
            if(bill == 10)
            {
                if(b5 >= 1)
                {
                    b10+=1;
                    b5-=1;
                }
                else
                {
                    flag = true;
                    break;
                }
            }
            if(bill == 20)
            {
                if(b10 >= 1 && b5 >= 1)
                {
                    b20+=1;
                    b10--;
                    b5--;
                }
                else if(b5 >= 3)
                {
                    b5-=3;
                    b20++;
                }
                else
                {
                    flag = true;
                    break;
                }
            }
        }
        
        if(flag == true)
            return false;
        return true;
    }
};