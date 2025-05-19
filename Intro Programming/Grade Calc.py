# 
# Kaden Sawyer
# Intro to Programming 163/006
# 3/16/2022
# This program can calculate grades based off of the user inputing the average grade 
# and the weighted percentage associated with that grade
# 

def calculateGrade(list1,list2):
    sum = 0
    numList1 = []
    for x in list1:
        x = float(x)
        sum+=x
        numList1.append(x)


    numList2 =[]
    for y in list2:
        y = float(y) / 100
        numList2.append(y)
    
    grade = 0
    pos = 0
    for k in numList2:
        grade += k *numList1[pos]
        pos+=1
        
    grade = (grade/sum) *100
    if grade >= 94:
        print(f" You have a {grade:.2f} percent for this class which is a A.")
    if grade < 94 and grade >= 90:
        print(f" You have a {grade:.2f} percent for this class which is a A-.")
    if grade <= 89 and grade >= 87:
        print(f" You have a {grade:.2f} percent for this class which is a B+.")
    if grade < 87 and grade >= 84:
        print(f" You have a {grade:.2f} percent for this class which is a B-.")
    if grade < 84 and grade >= 80:
        print(f" You have a {grade:.2f} percent for this class which is a B.")
    if grade < 80 and grade >= 77:
        print(f" You have a {grade:.2f} percent for this class which is a C+.")
    if grade < 77 and grade >= 74:
        print(f" You have a {grade:.2f} percent for this class which is a C.")
    if grade < 73 and grade >= 70:
        print(f" You have a {grade:.2f} percent for this class which is a C-.")
    if grade < 70 and grade >= 67:
        print(f" You have a {grade:.2f} percent for this class which is a D+.")
    if grade < 67 and grade >= 64:
        print(f" You have a {grade:.2f} percent for this class which is a D.")
    if grade < 64:
        print(f" You have a {grade:.2f} percent for this class which is a F.") 
    

    

    




weight = input("Enter weight percentage for each category seprated by a space ")
grade = input("Enter the average grade associated with each weight percentage in order ")

weightList  = weight.split()
gradeList = grade.split()
calculateGrade(weightList,gradeList)







66.625/85