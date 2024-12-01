class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int i = 0; i < arr.size(); i++) {
            int d = arr[i];
            
            
            if (mp.find(2 * d) != mp.end()) 
                return true;
            
            
            if (d % 2 == 0 && mp.find(d / 2) != mp.end()) 
                return true;
            
            mp[d] = i;  
        }
        return false; 
    }
};
