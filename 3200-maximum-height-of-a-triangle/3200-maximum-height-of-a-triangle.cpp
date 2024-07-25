class Solution {
public:
    int maxHeightOfTriangle(int r, int b) {
        int x = 0, c = 1, t = 0, red = r, blue = b;
        // first calculate for if the first ball is red
        while(red + blue >= c) {
            if(c % 2 == 0)
                if(blue >= c) blue -= c, c++, t++;
                else break;
            else
                if(red >= c) red -= c, c++, t++;
                else break;
        }
        x = max(x, t), c = 1, red = r, blue = b, t = 0;
        
        // calculate for if the first ball is blue
        while(red + blue >= c){
            if(c % 2 == 0) 
                if(red >= c) red -= c, c++, t++;
                else break;
            else
                if(blue >= c) blue -= c, c++, t++;
                else break;
        }
        return max(x, t);
    }
};