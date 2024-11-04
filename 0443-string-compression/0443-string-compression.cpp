#include <vector>
#include <string>

class Solution {
public:
    int compress(std::vector<char>& chars) {
        int index = 0;  
        int i = 0;

        while (i < chars.size()) {
            char currentChar = chars[i];
            int count = 0;

            
            while (i < chars.size() && chars[i] == currentChar) {
                i++;
                count++;
            }

            
            chars[index++] = currentChar;

            
            if (count > 1) {
                for (char c : std::to_string(count)) {
                    chars[index++] = c;
                }
            }
        }

        return index;
    }
};
