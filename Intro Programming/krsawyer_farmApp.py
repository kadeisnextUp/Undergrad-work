# 
# Kaden Sawyer
# Intro to Programming 163/006
# 4/10/2022
# This program creates a farm app that allows the user to create an animal on the farm
# 


class Animal():
    def __init__(self,type, name,gender,trophic):
        self.type = type
        self.gender = gender
        self.name = name
        self.trophic = trophic
     
    def printInfo(self):
        print(f"The {self.type} is a {self.name}")
        print(f"The {self.name} on the farm is a {self.trophic}")
 

class Chicken(Animal):
    def __init__(self, type, name, gender, trophic):
        super().__init__(type, name, gender, trophic)

    def crow(self):
        if self.gender == "male":
            print("The rooster crowed this morning")
        else:
            print("The hen probably didn't crow")
    

class Swine(Animal):
    def __init__(self, type, name, gender, trophic, dirty):
        super().__init__(type, name, gender, trophic)
        self.dirty = dirty

    def mud(self,dirty):
        if self.dirty == True:
            print("The pig is covered in mud")
        else:
            print("The pig isn't covered in mud")



class Sheep(Animal):
    def __init__(self, type, name, gender, trophic,sheared):
        super().__init__(type, name, gender, trophic)
        self.sheared = sheared
    
    def isSheared(self,sheared):
        if sheared == True:
            print("This sheep has been sheared.")
        else:
            print("This sheep has not been sheared.")

class Horse(Animal):
    def __init__(self, type, name, gender, trophic,breed):
        super().__init__(type, name, gender, trophic)
        self.breed = breed
        
    def printBreed(self):
        print(f"This horse is a {self.breed} breed")


if __name__ == "__main__": 
    x = False
    while x == False:
        print("All the animals in the farm. Type the corresponding number to make your animal")
        print("1.) Chicken(hen) \n2.) Chicken(rooster) \n3.) Sheep(ram) \n4.) Sheep(ewe)")
        print("5.) Swine(boar) \n6.) Swine(sow) \n7.) Horse(stallion) \n8.) Horse(mare) \n9.) exit")
        print("Enter number here: ",end="")
        choice = int(input())
        if choice == 1:
            chicken = Chicken("chicken","hen","female", "omnivore")
            chicken.printInfo()
            chicken.crow()
        elif choice == 2:
            chicken = Chicken("chicken","rooster","male", "omnivore")
            chicken.printInfo()
            chicken.crow()
        elif choice == 3:
            sheep = Sheep("sheep","ram","female", "herbivore",False)
            shear = input("Has the sheep been sheared? (type y or n)")
            shear.upper()
            if shear == "Y":
                sheep.sheared == True
            else:
                sheep.sheared == False
            sheep.printInfo()
            sheep.isSheared(sheep.sheared)
        elif choice == 4:
            sheep = Sheep("sheep","ewe", "female", "herbivore",False)
            shear = input("Has the sheep been sheared? (type y or n)")
            shear.upper()
            if shear == "Y":
                sheep.sheared == True
            else:
                sheep.sheared == False
            sheep.printInfo()
            sheep.isSheared(sheep.sheared)
        elif choice == 5:
            dirty = False
            mess = input("Is your pig dirty?(type y or n)")
            if mess == "y":
                dirty = True
            pig = pig = Swine("swine", "boar","male", "omnivore",dirty)
            pig.printInfo()
            pig.mud(dirty)
        elif choice == 6:
            dirty = False
            mess = input("Is your pig dirty?(type y or n)")
            if mess == "y":
                dirty = True
            pig = Swine("swine", "sow","female", "omnivore",dirty)
            pig.printInfo()
            pig.dirty(dirty)
        elif choice == 7:
            breed = input("what is the breed of your horse? ")
            horse = Horse("horse", "stallion", "male", "herbivore"," ")
            horse.breed = breed
            horse.printInfo()
            horse.printBreed
        elif choice == 8:
            breed = input("what is the breed of your horse? ")
            horse = Horse("horse", "stallion", "male", "herbivore"," ")
            horse.breed = breed
            horse.printInfo()
            horse.printBreed()
        elif choice == 9:
            x = True
            break
            










        