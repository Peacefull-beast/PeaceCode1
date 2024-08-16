class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {  
        int ans=0;
        int smallest=arr[0][0];
        int n=arr[0].size();
        int biggest=arr[0][n-1];
        for(int i=1;i<arr.size();i++)
        {
            n=arr[i].size();
            ans=max(ans,abs(arr[i][n-1]-smallest));
            ans=max(ans,abs(arr[i][0]-biggest));
            smallest=min(smallest,arr[i][0]);
            biggest=max(biggest,arr[i][n-1]);
        }
        return ans;
    }
};