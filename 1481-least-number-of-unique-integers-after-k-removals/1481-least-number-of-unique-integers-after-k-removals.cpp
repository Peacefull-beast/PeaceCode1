class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) 
    {
        unordered_map<int, int> freq;
        
        for(auto n : arr)
            freq[n]++;
        
        
        vector<pair<int, int>> freqVec(freq.begin(), freq.end());
        sort(freqVec.begin(), freqVec.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.second < b.second;
        });
        
        for(auto& pair : freqVec)
        {
            if(k >= pair.second)
            {
                k -= pair.second;
                freq.erase(pair.first);  
            }
            else
                break;
        }
        
        return freq.size();
    }
};
