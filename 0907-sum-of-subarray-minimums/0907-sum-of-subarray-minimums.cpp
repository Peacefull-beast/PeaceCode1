class Solution {
public:
    const int MOD = 1e9 + 7;
    
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n, 0);
        vector<int> right(n, 0);
        
        stack<pair<int, int>> sleft;
        stack<pair<int, int>> sright;
        
        // Calculate the number of subarrays where the current element is the minimum from the left
        for (int i = 0; i < n; i++) {
            int cnt = 1;
            while (!sleft.empty() && sleft.top().first >= arr[i]) {
                cnt += sleft.top().second;
                sleft.pop();
            }
            sleft.push({arr[i], cnt});
            left[i] = cnt;
        }
        
        // Calculate the number of subarrays where the current element is the minimum from the right
        for (int i = n - 1; i >= 0; i--) {
            int cnt = 1;
            while (!sright.empty() && sright.top().first > arr[i]) {
                cnt += sright.top().second;
                sright.pop();
            }
            sright.push({arr[i], cnt});
            right[i] = cnt;
        }
        
        // Calculate the sum of minimum subarrays modulo MOD
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = (ans + (long long)arr[i] * left[i] * right[i]) % MOD;
        }
        
        return ans;
    }
};
