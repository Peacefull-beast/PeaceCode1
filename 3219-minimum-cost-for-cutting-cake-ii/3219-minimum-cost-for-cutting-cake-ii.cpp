class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& h, vector<int>& v) {
        sort(h.begin(), h.end(), greater<int>());
        sort(v.begin(), v.end(),greater<int>());
        
        long long i = 0;
        long long j = 0;
        long long hp = 1;
        long long vp = 1;
        long long c = 0;
        while(i < h.size() && j < v.size())
        {
            if(h[i] >= v[j])//apply hcut
            {
                c += (h[i]*vp);
                hp++;
                i++;
            }
            else
            {
                c += (v[j]*hp);
                vp++;
                j++;
            }
        }
        
        while(i < h.size())
        {
            
            c += (h[i]*vp);
            hp++;
            i++;
            
        }
        while(j < v.size())
        {
            c += (v[j]*hp);
            vp++;
            j++;
        }
        
        return c;
    }
};