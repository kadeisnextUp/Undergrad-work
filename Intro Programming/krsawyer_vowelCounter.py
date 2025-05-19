# 
# Kaden Sawyer
# Intro to Programming 163/006
# 5/1/2022
# This program allows the user input a passage and then display the number of words in the passage,
# display the number of vowels, and display the count of each vowel
#


# returns the amount of words by spliting the string
def wordCounter(phrase):
    split = phrase.split()
    return len(split)

#recusivley counts the amount of vowels in a given phrase
def vowelCounter(phrase,n):

    if len(phrase)==0:
        return 0
    if phrase[0] in n:
        return vowelCounter(phrase[1:],n) +1
    else:
        return vowelCounter(phrase[1:],n)
    


test = input("Enter phrase ")
vowels = "aeiouAEIOU"


print("The amount of vowels:",vowelCounter(test,vowels))
print("The amount of words:", wordCounter(test))
    
    
   



