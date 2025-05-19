#include "Measurement.h"  // Include the class definition


//All code was developed by Javon Kimbrough, Kira Brown Johnson, and Kaden Sawyer

// === Constants ===
// These define fixed values that don't change in the program.
const int LITTLES_IN_LOT = 7;  // 1 lot consists of 7 littles
const int LOTS_IN_HEAP = 23;   // 1 heap consists of 23 lots

// === Default Constructor ===
// When an object of Measurement is created with no values, this sets everything to 0.
Measurement::Measurement() {
    littles = 0;
    lots = 0;
    heaps = 0;
}

// === Constructor with Specific Values ===
// This allows an object to be created with defined values for littles, lots, and heaps.
Measurement::Measurement(int littles, int lots, int heaps) {
    this->littles = littles;  // 'this->' refers to the class variable
    this->lots = lots;
    this->heaps = heaps;
}

// === Constructor with Total Littles ===
// This constructor converts a given number of 'littles' into 'lots' and 'heaps'.
Measurement::Measurement(int totalLittles) {
    // Convert total littles to heaps first (since 1 heap = 23 lots = 161 littles)
    heaps = totalLittles / (LITTLES_IN_LOT * LOTS_IN_HEAP);
    int remainingLittles = totalLittles % (LITTLES_IN_LOT * LOTS_IN_HEAP);

    // Convert remaining littles into lots (1 lot = 7 littles)
    lots = remainingLittles / LITTLES_IN_LOT;
    littles = remainingLittles % LITTLES_IN_LOT;  // Whatever is left remains as littles
}

// === Getters ===
// These functions return the private values so they can be accessed outside the class.
int Measurement::getLittles() const{
    return littles;  // Returns the number of littles
}

int Measurement::getLots() const {
    return lots;  // Returns the number of lots
}

int Measurement::getHeaps() const {
    return heaps;  // Returns the number of heaps
}

// === Setters ===
// These functions allow modification of private values while maintaining data integrity.
void Measurement::setLittles(int littles) {
    this->littles = littles;  // Assign the given value to the object's attribute
}

void Measurement::setLots(int lots) {
    this->lots = lots;
}

void Measurement::setHeaps(int heaps) {
    this->heaps = heaps;
}

// === Print Function ===
// This function prints the current measurement in a readable format.
void Measurement::printMeasurement() const {
    std::cout << heaps << " heaps, " << lots << " lots, " << littles << " littles" << std::endl;
}



//speacial functions
void Measurement::simplify() {
    //littles to lots
    if (littles >= 7) {
        lots += littles / 7;
        littles %= 7;
        
    }
    //lots to heaps
    if (lots >= 23) {
        heaps += lots / 23;
        lots %= 23;
    }
    if (littles < 0) {
        lots -= (abs(littles) / 7) + 1;
        littles = 7 - (abs(littles) % 7);
    }
    if (lots < 0) {
        heaps -= (abs(littles) / 23) + 1;
        lots = 23 - (abs(lots) % 23);
    }
    if (heaps < 0) {
        heaps = 0;
        littles = 0;
        lots = 0;
        
    }
}
int Measurement::inMeters() {
    int total = 0;
    total += littles;
    total += (lots * 7);
    total += (heaps * 161);
    return total;
    
}

//operator overload
void Measurement::operator-(const Measurement& test) {
    littles -= test.littles;
    lots -= test.lots;
    heaps -= test.heaps;
    simplify();
    
}
void Measurement::operator+(const Measurement& test ) {
    littles += test.littles;
    lots += test.lots;
    heaps += test.heaps;
    
    simplify();
}

void Measurement::operator*(const Measurement& test) {
    littles *= test.littles;
    lots *= test.lots;
    heaps *= test.heaps;
    
    simplify();
    
}

void Measurement::operator/(const Measurement& test) {
    littles /= test.littles;
    lots /= test.lots;
    heaps /= test.heaps;
    
    simplify();
}

bool Measurement::operator==(const Measurement& test) {
    return (littles == test.littles && lots == test.lots && heaps == test.heaps);
        
        
}

Measurement::operator std::string() const {
    return std::to_string(littles) + " littles " + std::to_string(lots) + " lots " + std::to_string(heaps) + " heaps ";
}