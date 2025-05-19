# 
# Kaden Sawyer
# Intro to Programming 163/006
# date
# oracle
# 

regions = ["North", "South", "Midwest", "West"]
regionprop = {"North":"above average", "South":"above average" , "Midewest":"above average", "West":"Below average"}

def user_pick(choices):
    print("Please choose an option: ")
    for idx, element in enumerate(choices):
        print("{}) {}".format(idx+1,element))
    i = input("Enter number: ")
    try:
        if 0 < int(i) <= len(choices):
            return int(i)
    except:
        pass
    return int(i)-1

print("Hello my name is Sally I will be helping you with your Water disaster needs")
print("what region are you from? ")
region = input("Enter region name: ")

choices = ["Option 1", "Option 2", "Option 3"]

for x in regions:
    if region in x:
        print(region)
        break
else:
    print("Please enter a correct region")

print("What would you like to learn about in your region \n"
"Your options are 1.Information about floods 2.Probability of FLooding in your area 3.Information about other regions")

choice = user_pick(choices)
def info():
    if choice == 1: 
        print("")
    if choice == 2:
        print("")
    if choice == 3:
        print("what region would you like to learn more about")
        new_region = input()
        print("What choice would you like to select for choosen region")
        #loop choices input option

    if choice == 4:
        print("")


region.capitalize