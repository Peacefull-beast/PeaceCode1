class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) 
    {
        unordered_map<int, int> freq;
        for(auto nums : arr1)
            freq[nums]++;
        
        vector<int> ans;
        for(auto num : arr2)
        {
            int n = freq[num];
            while(n--)
                ans.push_back(num);
            freq.erase(num);
        }
        
        vector<int> remaining;
        for(auto pair : freq)
        {
            int num = pair.first;
            int n = pair.second;
            while(n--)
                 remaining.push_back(num);
        }
        
        sort(remaining.begin(), remaining.end());
        ans.insert(ans.end(), remaining.begin(), remaining.end());
        
        return ans;
    }
};
