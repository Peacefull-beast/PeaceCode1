class Solution {
    
public:
    bool isSubsequence(string s, string t) 
    {
    //     // string temp="";
    //     // int i=0;
    //     // bool flag=str(s,t,temp,i);
    //     // return flag;
    //     int i=0;
    //     int j=0;
    //     while(i<s.length() && j<t.length())
    //     {
    //         if(s[i]==t[j])
    //             i++;
    //         j++;
    //     }
    //     if(i==s.length())
    //         return true;
    //     else
    //         return false;
    // 
         if(s=="")
             return true;
         if(t=="")
           return false;
         if(s[0]==t[0])
             return isSubsequence(s.substr(1),t.substr(1));
         else
             return isSubsequence(s,t.substr(1)); 
    }
    
};