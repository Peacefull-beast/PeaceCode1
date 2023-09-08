class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) 
    {
        map<int,int>mp;
        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(nums[i])!=mp.end())
                mp[nums[i]]++;
            else
                mp.insert(make_pair(nums[i],1));
        }
        vector<vector<int>> matrix;
        map<int,int>::iterator it;
        vector<int>temp;
        int x=0;
        while(mp.size()>0)
        {
            for(it=mp.begin();it!=mp.end();it++)
            {
                if(it->second!=0)
                {temp.push_back(it->first);
                 it->second--;  }
            }

            for(it=mp.begin();it!=mp.end();it++)
            {
                if(it->second<=0)
                    mp.erase(it);
            }
            //cout<<mp.size()<<"x ";
            matrix.push_back(temp);
            temp.clear();
        }
        return matrix;
        
    }
};