#ifndef PART_H
#define PART_H

#include <iostream>
#include <string>

using namespace std;

class Part {
private:
    int SKU; // stock keeping unit
    string Description;
    double Price;
    string UOM; // unit of measurement
    int QuantityOnHand; // current quantity
    int LeadTime; // days required to reorder if out of stock

public:
// constructor
    Part(int sku, const string& description, double price, const string& uom, int qtyOnHand = 0, int leadTime = 0);

// gets the part's info (SKU + Description)
    string GetPartInfo() const;

// gets the price
    double GetPrice() const;

// checks to see if in stock
    bool InStock() const;

// checks availability (days from today)
    bool Available(int daysFromToday) const;

// overloaded comparison operators (compare by SKU)
    bool operator>(const Part& other) const;
    bool operator<(const Part& other) const;
    bool operator==(const Part& other) const;

// display method for ASCII visualization
    void Display() const;
};

#endif 