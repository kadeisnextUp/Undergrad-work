# 
# Kaden Sawyer
# Intro to Programming 163/006
# December 8 2021
# This program opens a csv file called Grades and finds each students' average, the class average, 
# average male/female students, and the highest individual average
#  and returns all those averages in a formatted output.
# 

import csv
grades = []
maleStu = []
femaleStu = []
classAvgs = []
# finds average score in a list
def findAvg(studentList):
    gradesList = []
    for x in studentList:
        gradesList.append(float(x))
        studentList = gradesList
    average =(sum(gradesList)/ len(gradesList))
    return average

# puts female and male students average in seperate list and prints each students info 
# prints all the averages 
def studentInfo (file):
    for row in file:
        student = row[0]
        gender = row[1]
        grade = row[2:]
        
        print(f"{student} : {findAvg(grade):.2f}")

        if gender == "M":
            maleStu.append(findAvg(grade))
        if gender == "F":
            femaleStu.append(findAvg(grade))
        classAvgs.append(findAvg(grade))

    print(f"\nMale : {findAvg(maleStu):.2f}")
    print(f"Female : {findAvg(femaleStu):.2f}")
    print(f"\nClass : {findAvg(classAvgs):.2f}")
    print(f"\nStudent {student[classAvgs.index(max(classAvgs))]}",end=" ") 
    print(f"has the higest average of {max(classAvgs)}")



with open("C:\\Users\\Kaden Sawyer\\Downloads\\Grades.csv","r") as gradebook:
    readGrades = csv.reader(gradebook, delimiter = ",")
    header = next(readGrades)
    print("Name        Average")
    studentInfo(readGrades)

    
    
