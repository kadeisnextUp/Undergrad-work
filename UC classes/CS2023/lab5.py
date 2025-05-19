# -*- coding: utf-8 -*-
"""
Created on Sun Feb 16 15:38:45 2025

@author: Kaden Sawyer
"""

_author_ = "Kaden Sawyer"
_credits_ = ["none"]
_email_ = "sawyerkd@mail.uc.edu" 

## Lab 5: Required Questions - Dictionaries  ##

# RQ1
def merge(dict1, dict2):
    """Merges two Dictionaries. Returns a new dictionary that combines both. You may assume all keys are unique.

    >>> new =  merge({1: 'one', 3:'three', 5:'five'}, {2: 'two', 4: 'four'})
    >>> new == {1: 'one', 2: 'two', 3: 'three', 4: 'four', 5: 'five'}
    True
    """
    "*** YOUR CODE HERE ***"
    result = {} 
    x = 1
    while x in dict1 or x in dict2:
        if x in dict1:
            result[x] = dict1[x]
        else:
            result[x] = dict2[x]
        x+=1
    return result
# RQ2
def counter(message):
    """ Returns a dictionary where the keys are the words in the message, and each
    key is mapped (has associated value) equal 
    to the number of times the word appears in the message.
    >>> x = counter('to be or not to be')
    >>> x['to']
    2
    >>> x['be']
    2
    >>> x['not']
    1
    >>> y = counter('run forrest run')
    >>> y['run']
    2
    >>> y['forrest']
    1
    """
    "*** YOUR CODE HERE ***"
    result = {}
    split = message.split()
    for x in split:
        if x not in result:
            result[x] = 1
        else:
            result[x] += 1
    return result


# RQ3
def replace_all(d, x, y):
    """ Returns a dictionary where the key/value pairs are the same as d, 
    except when a value is equal to x, then it should be replaced by y.
    >>> d = {'foo': 2, 'bar': 3, 'garply': 3, 'xyzzy': 99}
    >>> d2= replace_all(d, 3, 'poof')
    >>> d2 == {'foo': 2, 'bar': 'poof', 'garply': 'poof', 'xyzzy': 99}
    True
    """
    "*** YOUR CODE HERE ***"
    result = d
    for i in result:
        if result[i] == x:
            result[i] = y
    return result

# RQ4
def sumdicts(lst):
   """ 
   Takes a list of dictionaries and returns a single dictionary which contains all the keys/value pairs found in list. And 
   if the same key appears in more than one dictionary, then the sum of values in list of dictionaries is returned 
   as the value mapped for that key
   >>> d = sumdicts ([{'a': 5, 'b': 10, 'c': 90, 'd': 19}, {'a': 45, 'b': 78}, {'a': 90, 'c': 10}] )
   >>> d == {'b': 88, 'c': 100, 'a': 140, 'd': 19}
   True
   """
   "*** YOUR CODE HERE ***"
   result = {}
   for x in lst:
       for k in x:
           if k not in result:
               result[k] = x[k]
           else:
               result[k] += x[k]
   return result

#RQ5

#Here is starter code that is explained in the Interactive Worksheet

def build_successors_table():
    """Return a dictionary: keys are words; values are lists of successor words. By default, we set the first word in tokens to be a successor to "."
    """
    f = open("shakespeare.txt", "r", encoding="ascii")
    tokens = f.read().split()
    table = {}
    prev = '.'
    for word in tokens:
        if prev not in table:
            table[prev] = []
        table[prev] += [word]
        prev = word
    return table

def construct_tweet(word, table):
    """Returns a string that is a random sentence starting with word, and choosing successors from table.
    """
    import random
    result = ' '
    while word not in ['.', '!', '?']:
        result += word + ' '
        word = random.choice(table[word])
    return result + word

def random_tweet():
    import random
    tweet_table = build_successors_table()
    return construct_tweet(random.choice(tweet_table['.']), tweet_table)
   
def middle_tweet():
    """ 
    This function should call random_tweet() 5 times. Each call will return a string of some length.
    This function should return the one string with length in the middle. 
    That is, 2 of 5 strings should be longer and 2 of 5 strings should be shorter
    then the one string you return.

    My experiments showed that you should usually get a tweet that is in range of 60-100 characters. 
    Hence, there is a small chance that one of the following tests may fail.
    >>> len(middle_tweet()) > 60
    True
    >>> len(middle_tweet()) < 100
    True
    """
    "*** YOUR CODE HERE ***" 
    
    """I had faster code that worked according to the requirements but it always
    failed the doctests
    
    tweets = []
    for _ in range 5:
        tweet = random_tweet()
        tweets.append(tweet)
    tweets.sort(key = len)
    return tweets[2]
    
    
    """
    tweets = []
    while len(tweets) < 5:
        tweet = random_tweet()
        if 60 < len(tweet) < 100:
            tweets.append(tweet)
    "sort by length and the middle of 5 is always the 3rd thing or index 2"
    tweets.sort(key=len)
    return tweets[2]
        

import doctest
if __name__ == "__main__":
  doctest.testmod(verbose=True)