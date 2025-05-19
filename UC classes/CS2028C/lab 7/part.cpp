#include "Part.h"

//constructor
Part::Part(int sku, const string& description, double price, const string& uom, int qtyOnHand, int leadTime)
    : SKU(sku), Description(description), Price(price), UOM(uom), QuantityOnHand(qtyOnHand), LeadTime(leadTime) {}

//gets SKU and Description as a single string
string Part::GetPartInfo() const {
    return to_string(SKU) + " - " + Description;
}

//gets price of the part
double Part::GetPrice() const {
    return Price;
}

//checks if the part is in stock
bool Part::InStock() const {
    return QuantityOnHand > 0;
}

//checks if the part will be available in the given number of days
bool Part::Available(int daysFromToday) const {
    //the part is available immediately
    if (QuantityOnHand > 0) {
        return true;
    }

    //checks if requested date is beyond lead time
    return daysFromToday >= LeadTime;
}

// overloaded comparison operators (compare by SKU)
bool Part::operator>(const Part& other) const {
    return this->SKU > other.SKU;
}

bool Part::operator<(const Part& other) const {
    return this->SKU < other.SKU;
}

bool Part::operator==(const Part& other) const {
    return this->SKU == other.SKU;
}

// Display method for ASCII visualization
void Part::Display() const {
    cout << "+-------------------------------+\n";
    cout << "| SKU: " << SKU << "\n";
    cout << "| Description: " << Description << "\n";
    cout << "| Price: $" << Price << "\n";
    cout << "| Unit of Measure: " << UOM << "\n";
    cout << "| Quantity On Hand: " << QuantityOnHand << "\n";
    cout << "| Lead Time: " << LeadTime << " days\n";
    cout << "+-------------------------------+\n";
}
