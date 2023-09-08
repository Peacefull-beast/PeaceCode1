class Solution(object):
    def divide(self, dividend, divisor):
        if dividend == -2**31 and divisor == -1:
            return 2**31 - 1
        
        # convert both integers to positive
        a, b = abs(dividend), abs(divisor)
        
        # initialize the quotient and remainder
        res = 0
        while a >= b:
            temp, i = b, 1
            while a >= temp:
                a -= temp
                res += i
                i <<= 1
                temp <<= 1
                
        # determine the sign of the quotient
        if (dividend > 0) != (divisor > 0):
            res = -res
        
        return res
        