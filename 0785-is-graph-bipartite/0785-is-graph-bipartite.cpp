class Solution {
public:
    bool answer(int start, int col, vector<vector<int>>& list, vector<int>& color, queue<int> &q)
    {
        q.push(start);
        color[start] = col;
        while(!q.empty())
        {
            int front = q.front();
            vector<int>neib = list[front];
            q.pop();
            for(int i =0;i<neib.size();i++)
            {
                if (color[neib[i]] == -1) 
                {
                    bool ans = answer(neib[i], !col, list, color, q);
                    if (ans == false)
                        return false;
                }
                else if (color[neib[i]] == col)
                return false;
            } 
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        queue<int>q;
        vector<int>color(n, -1);
        for(int i = 0; i<n; i++)
        {
            if(color[i] == -1)
            {
                if(answer(i,0, graph, color, q) == false)
                return false;
            }
        }
        return true;
    }
};