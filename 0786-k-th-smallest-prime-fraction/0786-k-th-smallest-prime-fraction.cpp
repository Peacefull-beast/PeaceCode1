class Solution {
public:
    typedef pair<double, pair<int,int>> ds;
    struct MyComparator 
    {
        bool operator()(ds a, ds b) const 
        {
        return a.first > b.first; 
        }
    };
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) 
    {
        
        vector<int>answer;
        priority_queue<ds, vector<ds>, MyComparator> pq;
        int  n = arr.size();
        
        
        for(int  i = 0; i < n-1; i++)
        {
            double myDouble = static_cast<double>(arr[i])/arr[n-1];
            pq.push({myDouble, {i, n-1} });
        }
        
        
        while(k>0)
        {
            ds top = pq.top();
            pq.pop();
            
            int numind = top.second.first;
            int denind = top.second.second;
            
            if(numind < denind-1)
            {
                
                double myDouble = static_cast<double>(arr[numind])/arr[denind-1];
                pq.push({myDouble, {numind,denind-1} });
            }
                
            k--;
            
            if(k == 0)
            {
                answer.push_back(arr[numind]);
                answer.push_back(arr[denind]);
                break;
            }                                                                      
        }
        return answer;
    }
};