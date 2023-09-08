class Solution {
public:
    int romanToInt(string s) 
    {
        int temp1=0;
        int temp2=0;
        int sum=0;
        int x=s.length();
        x=x-1;
            if(s[x]=='I')
            sum=1;
            if(s[x]=='V')
            sum=5;
            if(s[x]=='X')
            sum=10;
            if(s[x]=='L')
            sum=50;
            if(s[x]=='C')
            sum=100;
            if(s[x]=='D')
            sum=500;
            if(s[x]=='M')
            sum=1000;
            temp1=sum;
            cout<<sum<<"    ";
            for(int i=x-1;i>=0;i--)
            {
                if(s[i]=='I')
                temp2=1;
                if(s[i]=='V')
                temp2=5;
                if(s[i]=='X')
                temp2=10;
                if(s[i]=='L')
                temp2=50;
                if(s[i]=='C')
                temp2=100;
                if(s[i]=='D')
                temp2=500;
                if(s[i]=='M')
                temp2=1000;
                if(temp1==temp2)
                sum=sum+temp2;
                else if(temp2<sum)
                sum=sum-temp2;
                else
                sum=sum+temp2;
                temp1=temp2;
                cout<<sum<<"    ";
            }
            return sum;
    }
};