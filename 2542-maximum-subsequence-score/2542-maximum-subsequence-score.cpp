#define pii pair<int,int>
class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) 
    
    {
        // stores <value,index> from nums1 in decreasing order of values 
        priority_queue<pii> maxHeap;
        // stores <value,index> from nums2 in increasing order of values 
        priority_queue<pii,vector<pii>,greater<pii>> minHeap;

        long long ans=INT_MIN;
        long long score=0;
        long long sum=0;
        
        // push all the elements from nums1 into maxheap
        for(int i=0;i<nums1.size();i++) {
            maxHeap.push({nums1[i],i});
        }
        
        // sum the max k elements of nums1 and push the corresponding elements from nums2 into
        // minHeap
        while(!maxHeap.empty() && k>0) {
            pii top = maxHeap.top();
            sum+=top.first;
            minHeap.push({nums2[top.second],top.second});
            maxHeap.pop();
            k--;
        }

        // the top element from minHeap will give us the multiplier (min ele) to be multiplied
        // with the sum
        int minmul=minHeap.top().first;

        // calculate score for the top k elements and update ans
        score=sum*minmul;
        ans=max(ans,score);
         
        while(!maxHeap.empty()) {
            // get the minimum element from minHeap. This is our current multiplier
            // that is limiting our score. So, we will try to find a better ele to get max
            // score
            pii mintop=minHeap.top();
            // subtract the corresponding ele from nums1
            sum-=nums1[mintop.second];
            minHeap.pop();

            // get the next max element from the maxHeap to be added to sum
            pii maxtop=maxHeap.top();
            // add the element to sum
            sum+=maxtop.first;
            // push the correspoding ele to minHeap
            minHeap.push({nums2[maxtop.second],maxtop.second});
            maxHeap.pop();

            // get the limiting (min) value from minHeap
            minmul=minHeap.top().first;
            // update score and ans
            score=sum*minmul;
            ans=max(ans,score);
        }
        return ans;
    }
};