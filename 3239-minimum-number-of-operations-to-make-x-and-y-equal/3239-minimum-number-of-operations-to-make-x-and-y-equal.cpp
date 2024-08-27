class Solution {
public:
    int solve(int x, int y)
    {
        if(x == y)
        return 0;

        queue<pair<int,int>>q; //number,step
        unordered_set<int>st;
        q.push({x,0});
        st.insert(x);
        while(!q.empty())
        {
            int num = q.front().first;
            int step = q.front().second;
            q.pop();
            if(num == y)
                return step;

            if(num%11 == 0 && st.find(num/11) == st.end())
            {
                q.push({num/11,step+1});
                st.insert(num/11);
            }
            if(num%5 == 0 && st.find(num/5) == st.end())
            {
                q.push({num/5,step+1});
                st.insert(num/5);
            }

            if(st.find(num-1) == st.end())
            {
                q.push({num-1,step+1});
                st.insert(num-1);
            }
            if(st.find(num+1) == st.end())
            {
                q.push({num+1,step+1});
                st.insert(num+1);
            }
        }

        return -1;
        
    }
    int minimumOperationsToMakeEqual(int x, int y) 
    {
        return solve(x,y);
    }
};