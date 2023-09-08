class Solution {
public:
    string convert(string s, int numRows) 
    {
        int x=0;
        bool flag=true;
        vector<vector<char>> fans;
        for (int i=0;i<numRows;i++)
        {
            vector<char>temp;
            fans.push_back(temp);
        }
        while(x!=s.length())
        {
            for(int i=0;i<numRows;i++)    
            {
                fans[i].push_back(s[x]);
                x++;
                if(x==s.length())
                {
                    flag=false;
                    break;
                }
            }
            if(flag==false)
                break;
            for(int i=numRows-2;i>0;i--)
            { 
                fans[i].push_back(s[x]);
                x++;
                if(x==s.length())
                {
                    flag=false;
                    break;
                }
            } 
            if(flag==false)
                break;
        }
        int c=0;
        string str;
        while(c<fans.size())
        {
            for(int i=0;i<fans[c].size();i++)
                
                str=str+fans[c][i];
            c++;
            
        }
        return str;
    }
};