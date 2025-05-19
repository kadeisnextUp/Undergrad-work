# 
# Kaden Sawyer
# Intro to Programming 163/006
# 3/16/2022
# This program can calculate grades based off of the user inputing the average grade 
# and the weighted percentage associated with that grade
# 

stop = False
weightList = []
gradeList = []
while stop != True:
    gradeWeight = input("Enter the weight of the category out of 100/ (enter \"stop\" to stop)")
    gradeWeight.capitalize()
    if gradeWeight == "STOP":
        stop = True 
    else:
        gradeWeight = float(gradeWeight)
    avgGrade = float(input("Enter the average grade for that category out of 100"))
    weightList.append(gradeWeight)
    gradeList.append(gradeList)



66.625/85