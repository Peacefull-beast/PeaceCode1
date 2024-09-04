class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) 
    {
        int x = 0, y = 0;
        int d = 0; 
        int ans = 0;

        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
        set<pair<int, int>> obs;


        for (auto& p : obstacles)
            obs.insert({p[0], p[1]});


        for (int curr_cmd : commands) 
        {
            if (curr_cmd == -1)
                d = (d + 1) % 4;
            else if (curr_cmd == -2)
                d = (d + 3) % 4;
            else 
            {
                for (int s = 1; s <= curr_cmd; s++) 
                {
                    int nx = x + dir[d].first;
                    int ny = y + dir[d].second;

                    if (obs.find({nx, ny}) != obs.end())
                        break;

                    x = nx;
                    y = ny;

                    ans = max(ans, x * x + y * y); 
                }
            }
        }
        
        return ans;
    }
};
