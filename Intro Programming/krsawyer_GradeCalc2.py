# 
# Kaden Sawyer
# Intro to Programming 163/006
# 3/27/2022
# This program is a modification of my last grade calc project that 
# incoporates classes into the program and calculates a weighted grade from user inputs.
# 

class GradeCalculator:
    def __init__(self):
        self.weights = []
        self.avgerages = []
    
    def getWeights(self,user_weights):
        self.weights = user_weights
    def getAverages(self,user_averages):
        self.averages = user_averages
        
    def calculateGrade(self):
        sum = 0
        numList1 = []
        for x in self.weights:
            x = float(x)
            sum+=x
            numList1.append(x)


        numList2 =[]
        for y in self.averages:
            y = float(y) / 100
            numList2.append(y)
    
        grade = 0
        pos = 0
        for k in numList2:
            grade += k *numList1[pos]
            pos+=1
        
        grade = (grade/sum) *100
        return grade

    def print_info(self,grade):
        if grade >= 94:
            print(f"You have a {grade:.2f} percent for this class which is a A.")
        if grade < 94 and grade >= 90:
            print(f"You have a {grade:.2f} percent for this class which is a A-.")
        if grade <= 89 and grade >= 87:
            print(f"You have a {grade:.2f} percent for this class which is a B+.")
        if grade < 87 and grade >= 84:
            print(f"You have a {grade:.2f} percent for this class which is a B-.")
        if grade < 84 and grade >= 80:
            print(f"You have a {grade:.2f} percent for this class which is a B.")
        if grade < 80 and grade >= 77:
            print(f"You have a {grade:.2f} percent for this class which is a C+.")
        if grade < 77 and grade >= 74:
            print(f"You have a {grade:.2f} percent for this class which is a C.")
        if grade < 73 and grade >= 70:
            print(f"You have a {grade:.2f} percent for this class which is a C-.")
        if grade < 70 and grade >= 67:
            print(f"You have a {grade:.2f} percent for this class which is a D+.")
        if grade < 67 and grade >= 64:
            print(f"You have a {grade:.2f} percent for this class which is a D.")
        if grade < 64:
            print(f"You have a {grade:.2f} percent for this class which is a F.") 


if __name__ == "__main__":
    finalGrade = GradeCalculator()

    weight = input("Enter weight percentage for each category seprated by a space ")
    grade = input("Enter the average grade associated with each weight percentage in order seperated by a space ")
    
    #get the weight percetages and the average grades
    finalGrade.getWeights(weight.split())
    finalGrade.getAverages(grade.split())
    
    # calculated grade
    grade = finalGrade.calculateGrade()
    
    #printing the grade letter associated with the calculated grade
    finalGrade.print_info(grade)
