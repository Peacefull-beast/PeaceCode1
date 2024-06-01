class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) 
    {
        reverse(arr1.begin(), arr1.end());
        reverse(arr2.begin(), arr2.end());
        
        int i = 0;
        int c = 0;
        vector<int> ans;
        
        // Adding corresponding bits and managing carry
        while (i < arr1.size() || i < arr2.size() || c != 0) 
        {
            int bit1 = (i < arr1.size()) ? arr1[i] : 0;
            int bit2 = (i < arr2.size()) ? arr2[i] : 0;
            
            int sum = bit1 + bit2 + c;
            if (sum == 0 || sum == 1) {
                ans.push_back(sum);
                c = 0;
            } else if (sum == 2) {
                ans.push_back(0);
                c = -1;
            } else if (sum == 3) {
                ans.push_back(1);
                c = -1;
            } else if (sum == -1) {
                ans.push_back(1);
                c = 1;
            }
            i++;
        }
        
        while (ans.size() > 1 && ans.back() == 0) {
            ans.pop_back();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
