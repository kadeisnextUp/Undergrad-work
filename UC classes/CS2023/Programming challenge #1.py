# -*- coding: utf-8 -*-
"""
Created on Sat Feb  1 13:09:36 2025

@author: Kaden Sawyer
"""

_author_ = "Kaden Sawyer"
_credits_ = ["none"]
_email_ = "sawyerkd@mail.uc.edu" # Your email address


"finds the greatest common divisor between two numbers"
def gcd(a, b):
    """
    >>> gcd(3,4)
    1
    >>> gcd(60,48)
    12
    """
    if(b == 0):
        return abs(a)
    else:
        return gcd(b, a % b)
    
"returns a sum of unit fractions using the function gcd and the greedy approach"
def egypt(n,d):
    """
    >>> egypt(3,4)
    '1/2 + 1/4'
    >>> egypt(11,12)
    '1/2 + 1/3 + 1/12'
    >>> egypt(123,124)
    '1/2 + 1/3 + 1/7 + 1/64 + 1/8333 + 1/347186112'
    >>> egypt(103,104)
    '1/2 + 1/3 + 1/7 + 1/71 + 1/9122 + 1/141449381 + 1/100039636784966424'
    """
    result = ""
    while(n != 0 ):
        "find the next higest denominator if not 0"
        k = (d // n) + (1 if d % n != 0 else 0)
        
        "If the result string is not empty add + to it"
        if result:
            result += " + "
        result += f"1/{k}"
    
        "subtract from the fraction n/d"
        n = n * k - d
        d = d * k
        
        "use gcd to simplify"
        gcdValue = gcd(n, d)
        n = n // gcdValue
        d = d // gcdValue
        
    return result
        
        
import doctest
if __name__ == "__main__":
  doctest.testmod(verbose=True)
        
    
    
    
    