import MyFunc

data = MyFunc.addOneToMe(3)

if data == 4:
    print("Assert 3 got " + str(data)+" : PASS")
else:
    print("Assert 3 got "+ str(data)+" : FAIL")