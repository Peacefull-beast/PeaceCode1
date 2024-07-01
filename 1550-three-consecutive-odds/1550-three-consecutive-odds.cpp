class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) 
    {
        if(arr.size() < 3)
            return false;
        int ans = 0;
        for(int i=0;i<3; i++)
            if(arr[i]%2 != 0)
                ans++;
        
        if(ans == 3)
            return true;
        
        
        for(int i=3; i<arr.size(); i++)
        {
            if(arr[i-3]%2 != 0)
                ans--;
            if(arr[i]%2 != 0)
                ans++;
            
            if(ans == 3)
                return true;
        }
        
        return false;
            
    }
};