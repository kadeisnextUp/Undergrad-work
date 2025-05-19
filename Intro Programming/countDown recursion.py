
def countDown(value):
    if value == 1:
        print(value)
        print("Blast off")
        return
    print(value)
    countDown(value - 1)

countDown(5)