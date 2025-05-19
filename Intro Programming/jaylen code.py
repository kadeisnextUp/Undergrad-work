categories = {}

 

class AvgGrade:

    def __init__(self):

        self.x = 0

        self.y = 0

   

    def get_y(self,user_y):

        self.y = user_y

   

    def get_x(self,user_x):

        self.x = user_x

 

    def getLetterGrade(self, grade):

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

 

    def isWeightMax(catWeight):

        catWeight = sum(catWeight.values())

        print(f"You have {str(100 - catWeight)} remaining")

        return(not catWeight == 100)

 

    while isWeightMax(categories):

        cat, weight = input("Enter category and weight: ").split()

        categories[cat] = float(weight)

    print(categories)

 

    grade = 0.0

    for cat in categories.keys():

        grade += float(input("Enter grade for "+cat+": ")) * (categories[cat] / 100.0)

    print(f"you grade is {grade}")

 

if __name__=="__main__" :

    Avg_grade = AvgGrade()

    x = float(input())

    y = float(input())

    AvgGrade.get_x(x)

    AvgGrade.get_y(y)
    Avg_grade.getLetterGrade