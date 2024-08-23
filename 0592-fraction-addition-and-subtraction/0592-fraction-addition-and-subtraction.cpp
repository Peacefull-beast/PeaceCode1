class Solution {
public:
    string fractionAddition(string e) {
        if (e[0] != '-') 
            e = "+" + e;  // Ensure the string starts with a sign
        
        int numerator = 0, denominator = 1;  // Initialize to represent 0/1

        for (int i = 0; i < e.size();) {
            
            int sign = (e[i] == '-') ? -1 : 1;
            i++;
            
            
            int num = 0;
            while (isdigit(e[i])) 
            {
                num = num * 10 + (e[i] - '0');
                i++;
            }
            num *= sign; 
            
            
            i++;
            
            
            int den = 0;
            while (isdigit(e[i])) {
                den = den * 10 + (e[i] - '0');
                i++;
            }
            
            
            int common_den = lcm(denominator, den);
            
            
            numerator = numerator * (common_den / denominator) + num * (common_den / den);
            denominator = common_den;
        }
        
       
        int gcd_val = gcd(abs(numerator), denominator);
        numerator /= gcd_val;
        denominator /= gcd_val;
        
        return to_string(numerator) + "/" + to_string(denominator);
    }
    
private:
    
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    
    
    int lcm(int a, int b) {
        return a / gcd(a, b) * b;
    }
};
