class Solution {
public:
    char turnright(char c)
    {
        return (c == '9' ? '0' : c+1);
    }
    
    char turnleft(char c)
    {
        return (c == '0' ? '9' : c-1);
    }
    
    vector<string> nextturn(string s)
    {
        vector<string> ans;
        for(int i = 0; i<4; i++)
        {
            string cpy = s;
            cpy[i] = turnright(s[i]);
            ans.push_back(cpy);
            cpy[i] = turnleft(s[i]);
            ans.push_back(cpy);               
        }
        return ans;
    }
    int openLock(vector<string>& deadends, string target) 
    {
        queue<string>q;
        unordered_map<string, bool>vis;
        
        q.push("0000");
        vis["0000"] = true;
        
        int level = 0;
        unordered_set<string>deadend(deadends.begin(), deadends.end());
        
        while(q.empty() != true)
        {
            int size = q.size();
            while(size--)
            {
                string front = q.front();
                q.pop();
                
                if(front == target)
                    return level;
                
                
                if(deadend.find(front) != deadend.end())
                    continue;
                
                for(string option: nextturn(front))
                {
                    if(vis[option] != true)
                    {
                        q.push(option);
                        vis[option] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};