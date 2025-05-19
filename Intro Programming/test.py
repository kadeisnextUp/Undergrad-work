
import csv



with open("fileTester.txt") as line:
    readLine = csv.reader(line, delimiter = "")


    for k in readLine:
        print(k)

