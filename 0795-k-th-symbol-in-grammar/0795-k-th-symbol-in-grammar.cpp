class Solution {
public:
    int kthGrammar(int n, int k) 
    {
        if(n == 1)
        return 0;

        int x = (1 << (n-2));

        if(k > x)
        return 1 ^ kthGrammar(n-1, k-x);
        else
        return kthGrammar(n-1, k);
    }
};