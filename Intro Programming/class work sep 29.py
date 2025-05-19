# 
# Kaden Sawyer
# Intro to Programming 163/006
# 9/29/2021
# passing args and Scope Demo
# 

# def doHi():
#    print("Hi")
#    def doPride():
#        print("Aggie Pride")
#    doPride()



# start program
# print("Hello")
# doHi()

c = 0
def addMe(x):
    x+=1
    return x

c = addMe(c)
print(c)
