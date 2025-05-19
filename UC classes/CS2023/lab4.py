# -*- coding: utf-8 -*-
"""
Created on Sat Feb  8 13:24:25 2025

@author: Kaden Sawyer
"""


_author_ = "Kaden Sawyer"
_credits_ = ["none"]
_email_ = "sawyerkd@mail.uc.edu" # Your email address

##Lab04 Required Questions ##

#########
# Lists #
#########

# RQ1
def cascade(lst):
    """Returns the cascade of the given list running forward and back.

    >>> cascade([1, 2, 3, 4])
    [1, 2, 3, 4, 4, 3, 2, 1]
    """
    "*** YOUR CODE HERE ***"
    new  = lst + lst[::-1]
    return new
        
    

# RQ2
def maptwice(fn, seq):
    """Applies fn twice onto each element in seq and returns the resulting list.

    >>> maptwice(lambda x: x*x, [1, 2, 3])
    [1, 16, 81]
    """
    "*** YOUR CODE HERE ***"
    i = 0
    result = []
    for x in seq:
        result += [fn(x)]
    for k in result:
        result[i] = fn(k)
        i += 1
    return result

#RQ3
def filterout(pred, seq):
    """Keeps elements in seq only if they do not satisfy pred.

    >>> filterout(lambda x: x % 2 == 0, [1, 2, 3, 4])
    [1, 3]
    """
    "*** YOUR CODE HERE ***"
    result = []
    for x in seq:
        if not(pred(x)):
            result += [x]
    return result

#RQ4
def comp(n, pred):
    """ Uses a one line list comprehension to return list of the first n integers (0...n-1) which satisfy the predicate pred.
    >>> comp(7, lambda x: x%2 ==0)
    [0, 2, 4, 6]
    """
    "*** YOUR CODE HERE ***"
    return [x for x in range(n) if(pred(x))]
#RQ5
def flatten(lst):
    """ Takes a nested list and "flattens" it.
    
    >>> flatten([1, 2, 3]) 
    [1, 2, 3]
    >>> x = [1, [2, 3], 4]      
    >>> flatten(x)
    [1, 2, 3, 4]
    >>> x = [[1, [1, 1]], 1, [1, 1]] 
    >>> flatten(x)
    [1, 1, 1, 1, 1, 1]
    >>> lst = [1, [[2], 3], 4, [5, 6]]
    >>> flatten(lst)
    [1, 2, 3, 4, 5, 6]
    """
    "*** YOUR CODE HERE ***"
    result = []
    for x in lst:
       if(not(type(x) == list)):
           result += [x]
       else:
           result += flatten(x)
    return result
            

import doctest
if __name__ == "__main__":
  doctest.testmod(verbose=True)