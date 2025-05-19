# -*- coding: utf-8 -*-
"""
Created on Mon Apr 14 11:52:12 2025

@author: Kaden Sawyer
"""
_author_ = "Kaden Sawyer"
_credits_ = ["none"]
_email_ = "sawyerkd@mail.uc.edu"


"""
When trying to imporve the performance of the allsteps(word) function, I had to apply some optimizations. 
First, I converted the word list into a set for constant-time lookups, this would speedn up dictionary checks. 
Next, instead of generating all possible anagrams I used collections. I then used
collections.Counter to represent the letter frequencies of the input word and each candidate. 
This allowed me to compare words based on character counts rather than sorting or permuting letters. 
Lastly, I also filtered candidates by length, checking only words that are exactly one letter longer than the input, reducing unnesscary reductions.

"""

url = "http://raw.githubusercontent.com/eneko/data-repository/master/data/words.txt"
import os
import string
from urllib.request import urlopen
#used to count
from collections import Counter
wordfile = urlopen(url)
words = wordfile.read().decode('utf-8').upper().split()
wordSet = set(words)




def allsteps(word):
    '''
    >>> allsteps("APPLE")
    ['ALEPPO', 'APPEAL', 'CAPPLE', 'DAPPLE', 'LAPPED', 'LAPPER', 'LAPPET', 'PALPED', 'PAPULE', 'RAPPEL', 'UPLEAP']

    >>> allsteps("UC")
    ['CUB', 'CUD', 'CUE', 'CUM', 'CUP', 'CUR', 'CUT', 'LUC', 'UCA']

    >>> allsteps("BEARCAT")
    ['ACERBATE', 'BACTERIA', 'BRACCATE', 'BRACTEAL', 'CARTABLE', 'SCABRATE']

    '''
    word = word.upper()
    baseCount = Counter(word)
    result = set()
    
    for letter in string.ascii_uppercase:
        newCount = baseCount + Counter(letter)
        for candidate in wordSet:
            if len(candidate) != len(word) + 1:
                continue
            if Counter(candidate) == newCount:
                result.add(candidate)
    return sorted(result)

#extra credit


import doctest
if __name__ == "__main__":
  doctest.testmod(verbose=True)

