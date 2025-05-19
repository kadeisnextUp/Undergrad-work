# 
# Kaden Sawyer
# Intro to Programming 163/006
# Oct 8 2021
# In class work
# 


def factor(x):
    factorList = []
    if x %2 != 0:
        factorList = [1,x]
    else:
        k=1
        while k != x+1:
            if (x/k)%1 == 0  :
                factorList.append(k)
            k+=1
    return factorList


num = int(input("Enter a number "))

print(f"These are the factors for {num}", factor(num))
if len(factor(num)) == 2:
    print(num,"is a prime number")
