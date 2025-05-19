# -*- coding: utf-8 -*-
"""
Created on Mon Apr 21 00:12:01 2025

@author: Kaden Sawyer
"""

_author_ = "Kaden Sawyer"
_credits_ = ["none"]
_email_ = "sawyerkd@mail.uc.edu"


#RQ1
class Cheer():
    """
    >>> UC = Cheer("Bearcats")
    >>> for c in UC:
    ...     print(c)
    ...
    Give me an B
    Give me an e
    Give me an a
    Give me an r
    Give me an c
    Give me an a
    Give me an t
    Give me an s
    """
    def __init__(self, word):
        self.word = word
    
    def __iter__(self):
        self.index = 0
        return self
    
    def __next__(self):
        if self.index < len(self.word):
            letter = self.word[self.index]
            self.index += 1
            return f"Give me an {letter}"
        else:
            raise StopIteration
   

#RQ2
class Countdown:
    """
    An iterator that counts down from N to 0.
    >>> for number in Countdown(5):
    ...     print(number)
    ...
    5
    4
    3
    2
    1
    0
    >>> for number in Countdown(2):
    ...     print(number)
    ...
    2
    1
    0
    """
    
    def __init__(self, n):
        self.n = n
    
    def __iter__(self):
        return self
    
    def __next__(self):
        if self.n >= 0:
            current = self.n
            self.n -= 1
            return current
        else:
            raise StopIteration

 

##############
# Generators #
##############

# RQ3a
def evens():
    """A generator function that yields the infinite sequence of all even natural
    numbers, starting at 1.

    >>> m = evens()
    >>> type(m)
    <class 'generator'>
    >>> [next(m) for _ in range(5)]
    [2, 4, 6, 8, 10]
    """
    num = 2
    while True:
       yield num
       num += 2
   
        
# RQ3b        
def naturals():
    """A generator function that yields the infinite sequence of natural
    numbers, starting at 1.

    >>> m = naturals()
    >>> type(m)
    <class 'generator'>
    >>> [next(m) for _ in range(10)]
    [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    """
    num = 1
    while True:
       yield num
       num += 1
    
        
#RQ4
def scale(s, k):
    """Yield elements of the iterable s scaled by a number k.

    >>> s = scale([1, 5, 2], 5)
    >>> type(s)
    <class 'generator'>
    >>> list(s)
    [5, 25, 10]
    >>> m = scale(naturals(), 2)
    >>> [next(m) for _ in range(5)]
    [2, 4, 6, 8, 10]
    """
    for item in s:
        yield item * k
    

# RQ5
def countdown(n):
    """
    A generator that counts down from N to 0.
    >>> for number in countdown(5):
    ...     print(number)
    ...
    5
    4
    3
    2
    1
    0
    >>> for number in countdown(2):
    ...     print(number)
    ...
    2
    1
    0
    """
    
    for i in range(n,-1,-1):
        yield i

# RQ6
def hailstone(n):
    """
    >>> for num in hailstone(10):
    ...     print(num)
    ...
    10
    5
    16
    8
    4
    2
    1
    """
    while n != 1:
       yield n
       if n % 2 == 0:
           n = n // 2
       else:
           n = 3 * n + 1
    yield 1
   

   
import doctest
if __name__ == "__main__":
  doctest.testmod(verbose=True)