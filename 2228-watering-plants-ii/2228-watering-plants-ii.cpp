class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) 
    {
        int a = capacityA;
        int b = capacityB;

        int i = 0;
        int j = plants.size()-1;

        int ans = 0;
        while(i <= j)
        {
            if(a < plants[i] && i != j)
            {
                a = capacityA;
                ans++;
            }

            if(b < plants[j] && i != j)
            {
                b = capacityB;
                ans++;
            }

            if(i == j)
            {
                if(a >= plants[i] || b >= plants[i])
                break;

                ans++;

            }
            a -= plants[i];
            b -= plants[j];
            i++;
            j--;
        }

        return ans;
    }
};