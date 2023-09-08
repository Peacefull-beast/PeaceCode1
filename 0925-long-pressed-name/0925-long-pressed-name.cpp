class Solution {
public:
    bool isLongPressedName(string name, string typed) 
    {
        int i=0;
        int j=0;
        bool flag=true;
    
        while(i<name.length() && j<typed.length())
        {
            if(name[i]==typed[j] && name[i+1]==typed[j+1])
            {
                i++;
                j++;
            }
            else if(name[i]==typed[j] && name[i+1]!=typed[j+1])
            j++;
            else if(name[i]!=typed[j])
            {
                flag=false;
                break;
            }
        }
        if(i==name.length())
        return flag;
        else return false;
    }
};