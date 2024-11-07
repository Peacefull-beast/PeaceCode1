#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int largestCombination(vector<int>& cand) {
        int maxCount = 0;
        
        for (int bit = 0; bit < 32; ++bit) {
            int count = 0;
            for (int num : cand) {
                
                if (num & (1 << bit)) {
                    count++;
                }
            }
            
            maxCount = max(maxCount, count);
        }
        
        return maxCount;
    }
};
