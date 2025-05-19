
from typing import Text


num = open("C:\\Users\\Kaden Sawyer\\OneDrive\\Documents\\data.txt")

line  = num.readlines()
num.close()

for x in line:
    print(x)
