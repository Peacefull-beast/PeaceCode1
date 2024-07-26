class Solution {
public:
    bool isPerfectSquare(int num) {
        int start = 1;
        bool flag;
        long long end = num, mid = start + (end - start)/2;
        while(start <= end )
        {
            long long sq = mid*mid;
            if (sq == num)
            {
                flag = 1;
                break;
            }
            else if(sq > num)
            {
                end  = mid-1;           
            }
            else
            {
                start = mid+1;
                flag = 0;
            }
             mid = start + (end - start)/2;
        }
            
        return flag;
    }
};