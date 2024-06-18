class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int, int>> job;
        
        for (int i = 0; i < profit.size(); i++) {
            job.push_back({difficulty[i], profit[i]});
        }
        
        sort(job.begin(), job.end());
        sort(worker.begin(), worker.end());
        
        int ans = 0;
        int maxProfit = 0;
        int j = 0;
        
        for (int i = 0; i < worker.size(); i++) {
            while (j < job.size() && worker[i] >= job[j].first) {
                maxProfit = max(maxProfit, job[j].second);
                j++;
            }
            ans += maxProfit;
        }
        
        return ans;
    }
};
