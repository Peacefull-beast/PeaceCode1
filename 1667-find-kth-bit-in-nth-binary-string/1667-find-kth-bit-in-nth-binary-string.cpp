class Solution {
public:
    char findKthBit(int n, int k) 
    {
        if(n == 1)
        return '0';


        int len = (1 << n) - 1;

        int mid = len/2 + 1;//find length of find string

        if(k == mid)
        return  '1';//that's how string is derived

        else if(k < mid)
        return findKthBit(n-1, k);//if k is in first half it lies in sn-1

        else
        return findKthBit(n-1, len-k+1) == '0' ? '1' : '0';//if lies in second half invert bit in 1st half of k


    }
};