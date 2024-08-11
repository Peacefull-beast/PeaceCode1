class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) 
    {
        int cell = 0;
        for(auto dir: commands)
        {
            if(dir == "UP")
                cell -= n;
            else if(dir == "DOWN")
                cell += n;
            
            else if(dir == "RIGHT")
                cell += 1;
            else
                cell -= 1;
        }
        
        return cell;
    }
};