# 
# Kaden Sawyer
# Intro to Programming 163/006
# November 8 2021
# A program that list each plane operator and the total crashes for that operator
# 
import csv
crashesDict = {}

with open("C:\\Users\\Kaden Sawyer\\Downloads\\Crashes_Of_Airplanes.csv","r") as operator:
    readCrash = csv.reader(operator,delimiter = ",")

    
    for i in readCrash:
        #print(i[3])
        if i[3] in crashesDict.keys():
            crashesDict[i[3]]+=1
        else:
            crashesDict.update({i[3]:1})

print(crashesDict)

#for op, crash in crashesDict.items():
   # if crash > 50:
    #    print(op+ " : "+str(crash))

        
    

#crashes = open("C:\\Users\\Kaden Sawyer\\Downloads\\Crashes_Of_Airplanes.csv")
#eachCrash = crashes.read()
#crashes.close()
#print(eachCrash)