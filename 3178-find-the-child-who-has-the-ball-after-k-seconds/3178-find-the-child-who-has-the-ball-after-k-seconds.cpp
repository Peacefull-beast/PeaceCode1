class Solution {
public:
    int numberOfChild(int n, int k) 
    {
        n--;
        int rounds = k / n; 
        int rem = k % n; 

        if(rounds % 2 == 0) 
            
            return rem; // The ball is passed forward from the start
        else 
            
            return (n - rem); // The ball is passed backward from the end
        
    }
};