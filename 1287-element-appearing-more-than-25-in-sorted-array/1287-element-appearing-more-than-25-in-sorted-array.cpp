class Solution {
public:
    int findSpecialInteger(vector<int>& a) 
    {
        int n=a.size();
        int t=n/4;
        for(int i=0;i<n; i++)
            if(a[i]==a[i+t])
                return a[i];
        
        return 0;
    }
};