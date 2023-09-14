class Solution {
public:
    void dfs(int n,int curr, vector<vector<int>>& graph, vector<int>& path, vector<vector<int>>&ans)
    {
        if(curr == n)
            ans.push_back(path);
        else
        {
            for(int i=0;i<graph[curr].size();i++)
            {
                cout<<("1...");
                //curr = graph[curr][i];
                path.push_back(graph[curr][i]);
                dfs(n,graph[curr][i],graph,path,ans);
                path.pop_back();
            }
            
        }
            
                   
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<int>path;
        path.push_back(0);
        vector<vector<int>>ans;
        dfs(graph.size()-1,0,graph,path,ans);
        return ans;
            
        }
    };