# 
# Kaden Sawyer
# Intro to Programming 163/006
# Oct 30 2021
# A Registraion line program that finds the smallest area of frustration in the line
# 

def registraionLine():
    aggieLine = int(input("Enter the number of people in the line "))
    line = range(1,aggieLine)
    ranNum = ""
    count = 0
    regLine =[]
    while count != 3:
        ranNum = int(input("Enter the aggie's position in the line "))
        regLine.append(ranNum)
        count+=1
    
    regLine.sort()
    return regLine

# area of frustraion = (position right -(1/2)len(position to position right)) - 
# (posistion-(1/2)len(position to position left)) 
    
def frustraion(list):
    posRight = list[2]
    pos = list[1]
    posLeft = list[0]
    areaLeft =float(pos-(1/2)*(pos-posLeft))
    areaRight = float(posRight-(1/2)*(posRight-pos))


    if(areaLeft < areaRight):
        return areaRight - areaLeft
    else:
       return areaLeft - areaRight





theLine = registraionLine()
frus = frustraion(theLine)
print(f"The area of frustration is {frus:.1f}")



