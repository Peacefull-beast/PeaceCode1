#define pi pair<int, int>
class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int j = 0, n = profits.size();
        vector<pi> temp;
        priority_queue<int> maxHeap;

        for(int i = 0; i < n; ++i) {
            temp.push_back({capital[i], profits[i]});
        }

        sort(begin(temp), end(temp));
        while(k--) {
            while(j < n && w >= temp[j].first) {
                maxHeap.push(temp[j++].second);
            }

            if(maxHeap.empty()) break;
            w += maxHeap.top();
            maxHeap.pop();
        }

        return w;
    }
};