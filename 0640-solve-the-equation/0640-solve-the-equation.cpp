#include <string>
#include <cctype> 
using namespace std;

class Solution {
public:
    string solveEquation(string s) {
        bool equal = true; 
        int var = 0;       
        int rhs = 0;       
        
        for (int i = 0; i < s.size();) {
            int sgn = equal ? 1 : -1; 
            int num = 0;
            bool isNumber = false;     

            
            if (s[i] == '+') 
                i++; 
            else if (s[i] == '-') 
            {
                sgn = -sgn; 
                i++;
            }

            while (i < s.size() && isdigit(s[i])) 
            {
                num = num * 10 + (s[i] - '0');
                i++;
                isNumber = true;
            }


            if (i < s.size() && s[i] == 'x') 
            {
                if (!isNumber) num = 1; 
                var += (sgn * num);     
                i++;
            }
            else 
                rhs += (sgn * num); 

            if (i < s.size() && s[i] == '=') 
            {
                equal = false; 
                i++;
            }
        }

        rhs = -rhs;

        if (var == 0 && rhs != 0) 
            return "No solution";
        else if (var == 0 && rhs == 0) 
            return "Infinite solutions";
        else 
            return "x=" + to_string(rhs / var);
       
    }
};
