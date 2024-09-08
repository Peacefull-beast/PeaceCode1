class Solution 
{
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        vector<int> hash(26, 0);
        
        priority_queue<int> pq;

       
        int s = tasks.size();
        for (int i = 0; i < s; i++) {
            hash[tasks[i] - 'A']++;
        }

        
        for (int i = 0; i < 26; i++) {
            if (hash[i]) {
                pq.push(hash[i]);
            }
        }
        
        int idle = 0;
        while (!pq.empty()) 
        {
            int cycle = n + 1;
            int count = 0;
            vector<int> temp;
            
            while (count != cycle && !pq.empty()) 
            {
                count++;
                
                int a = pq.top() - 1;
                pq.pop();
                if (a)
                    temp.push_back(a);
            }
            if (temp.size() > 0 && pq.empty())
                idle += (cycle - count);
            for (int i = 0; i < temp.size(); i++)
                pq.push(temp[i]);
        }
        return s + idle;
    }
};
    