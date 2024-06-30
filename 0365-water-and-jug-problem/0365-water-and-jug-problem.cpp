class Solution {
public:
    bool canMeasureWater(int x, int y, int target) 
    {
        vector<int>step = {x, -x, y, -y};
        int z = x+y;
        vector<int>vis(z+1, 0);
        
        queue<int>q;
        q.push(0);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            vis[node] = 1;
            
            if(node == target)
                return true;
            
            for(int i=0;i<4; i++)
            {
                int nnode = node + step[i];
                if(nnode > 0 && nnode < z+1 && vis[nnode] == 0)
                    q.push(nnode);
            }
        }
        
        return false;
    }
};