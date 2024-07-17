class Solution {
public:
    long long maximumPoints(vector<int>& enemy, int current) 
    {
        sort(enemy.begin(), enemy.end());
        
        long long j = enemy.size()-1;
        long long i = 0;
        long long points = 0;
        while(i <= j)
        {
            if(current >= enemy[i])
            {
                points += current / enemy[i];
                current %= enemy[i];
            }
            else
            {
                if(points >= 1)
                {
                    current += enemy[j];
                    j--;
                }
                else
                    break;
            }
        }
        return points;
    }
};