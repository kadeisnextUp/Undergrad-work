#
# Derrick Leflore
# Comp 163 
# Sep 24 2021
# Fruit stand application : 
#

# Tax rates
stateTax = 0.05
federalTax = 0.075
totalState = 0.0
totalFederal = 0.0

# fruit stand inventory
inventoryPrice = {"Apple":0.0,"Orange":0.0,"Pear":0.0}
inventoryTotals = {"Apple":0.0,"Orange":0.0,"Pear":0.0}

# set price of fruit
for fruit in inventoryPrice :
    fruitCost = float(input("Enter the cost of "+fruit+" : "))
    inventoryPrice.update({fruit:fruitCost})

standOpen = True

# Calc purchaces while stand is open
while standOpen :
    # Display Stand menu
    print("1. Customer Sale")
    print("2. Close Stand")
    print("")
    selection = int(input("Enter Selection : "))

    if selection == 1:
        quantity = 0

        subTotal = 0.0
        subStateTax = 0.0
        subFederalTax = 0.0
        for fruit in inventoryPrice:
           quantity = int(input("Quantity of "+fruit +" : "))
           subTotal += quantity * inventoryPrice.get(fruit)
           inventoryTotals.update({fruit:( inventoryTotals.get(fruit) 
            + quantity)})
        subStateTax = subTotal * stateTax
        subFederalTax = subTotal * federalTax
        totalState += subStateTax
        totalFederal += subFederalTax

        print("***********")
        print("Recipt")
        print("")
        print("Subtotal : "+str(subTotal))
        print(f"Tax State : {subStateTax:.2f}")
        print(f"Tax Federal : {subFederalTax:.2f}")
        total = subFederalTax+subStateTax+subTotal
        print(f"Total : {total:.2f}")
        print("")
    elif selection == 2:
        print("")
        print("Closing Stand....calulating totals")
        standOpen = False
    else:
        print("Invalid Selection")
        print("")
else:    
    dailySales = 0.0
    print("**********************")
    print("Daily Totals")
    print("**********************")
    print("")
    
    for fruit in inventoryTotals:
        dailyFruitSales = 0
        dailyFruitSales += inventoryTotals[fruit] * inventoryPrice[fruit]
        # dailyFruitSales += inventoryTotals.get(fruit) * inventoryPrice.get(fruit)
        print(fruit +f": count {inventoryTotals.get(fruit):.0f}" +
            f" : sales {dailyFruitSales:.2f}")
        dailySales += dailyFruitSales
    # for inventory totals

    print(f"Sales : {dailySales:.2f}")
    print(f"State : {totalState:.2f}")
    print(f"Federal : {totalFederal:.2f}")
    dailyTotal = dailySales+totalFederal+totalState
    print(f"Daily total : {dailyTotal:.2f}")
# while stand Open    